#include <bits/stdc++.h>
using namespace std;

/* 
Nesse problema � importante usar unsigned para garantir a corretude
para os valores nos extremos do range dos inteiros, maiores que (2^32)/2
*/

string convert_to_bin(unsigned int num){
	
	int remainder;
	string bin;
	
	if(num == 0){
		bin = "0";
	}
	else{
		while(num >= 1){
			remainder = num % 2;
			num = num / 2;
			if(remainder == 1){
				bin.insert(0, "1");
			}
			else{
				bin.insert(0, "0");
			}
		}
	}

	// como a representa��o deve ser em 32 bits, com o bin�rio em m�os,
	// � criada uma string com os d�gitios faltantes, preenchida por zeros.
	// Ao concatenar essas zeros ao bin�rio, conseguimos a representa��o desejada.
	string complement_bin(32 - bin.size(), '0');
	bin = complement_bin + bin;
	
	return bin;
}


string mofiz_sum(string bin1, string bin2){

	int digit_sum;
	string bin_sum;
	
	for(int i = 0; i < bin1.size(); i++){
		// char - '0' convers�o para o inteiro correspondente �quela char 
		digit_sum = (bin1[i] - '0') + (bin2[i] - '0');
		
		if(digit_sum == 0 or digit_sum == 2){
			bin_sum += "0";
		}
		else{
			bin_sum += "1";
		}
	}

	return bin_sum;
}


unsigned int reconvert_to_int(string bin_sum){
	
	string bin_number;
	int pos, bin_digit;
	unsigned int converted_bin, power;
	
	for(int i = 0; i < bin_sum.size(); i++){
		pos = 32 - i - 1;
		bin_digit = (bin_sum[i] - '0'); // obs: aqui � 'i' e n�o 'pos' porque a posi��o no bin�rio � contr�ria ao percorriemtno do index
		power = pow(2, pos);
		converted_bin += (power * bin_digit);
	}
		
	return converted_bin;
}


int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 0; i < inputs.size(); i++){
		
		string input = inputs[i];
	
		istringstream iss(input);
		unsigned int num1, num2;
		iss >> num1 >> num2;
		
		string bin1 = convert_to_bin(num1);
		string bin2 = convert_to_bin(num2);
		string bin_sum = mofiz_sum(bin1, bin2);
		unsigned int converted_bin = reconvert_to_int(bin_sum);
	
		cout << bin1 << endl << bin2 << endl;
		cout << converted_bin << endl;
			
	}
	
	return 0;
}
