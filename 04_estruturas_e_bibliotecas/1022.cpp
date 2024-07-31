#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string str, char delimiter){
	
	vector<string> sep_strings;
	
	int first_non_delimiter_index = 0;
	while(str[first_non_delimiter_index] == delimiter){
		first_non_delimiter_index++;
	}
	
	int i = first_non_delimiter_index;
            int first_char = first_non_delimiter_index;
            int last_char = first_non_delimiter_index;

	while(i <= str.size()){
		if(str[i] == delimiter || i == str.size()){
			last_char = i;
			string sub = str.substr(first_char, last_char - first_char);
			sep_strings.push_back(sub);
			first_char = last_char + 1;
		}
		i++;
	}
	
	return sep_strings;
}


tuple<int, int> find_numerator_denominator(vector<string> instance){
	
	int N1 = stoi(instance[0]);
	int D1 = stoi(instance[2]);
	int N2 = stoi(instance[4]);
	int D2 = stoi(instance[6]);
	
	string operation = instance[3];
	int numerator, denominator; 
	
	if(operation == "+"){
		numerator = N1*D2 + N2*D1;
		denominator = D1*D2;
	}
	if(operation == "-"){
		numerator = N1*D2 - N2*D1;
		denominator = D1*D2;
	}
	if(operation == "*"){
		numerator = N1*N2;
		denominator = D1*D2;
	}
	if(operation == "/"){
		numerator = N1*D2;
		denominator = N2*D1;
	}
	// como em c++ uma função só retorna um valor, aqui é feita uma tupla que armazena os dois valores desejados
	return make_tuple(numerator, denominator);
}


// algoritmo de Euclides para encontrar o máximo divisor comum (MDC) entre o numerador e o denominador finais
int MDC(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    if(a < 0){
    	a = a * (-1);
	}
	
    return a;
}


int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 1; i < inputs.size(); i++){

		char delimiter = ' '; 
		vector<string> instance = split_string(inputs[i], delimiter);

		tuple<int, int> num_den = find_numerator_denominator(instance);
		// forma de acessar cada elemento da tupla: usando o get e o indice
		// OBS: tuplas não necessariamente são dois valores, podem ser mais
		int numerator = get<0>(num_den);
		int denominator = get<1>(num_den);
		
		int mdc = MDC(numerator, denominator);

		// Para garantir que caso o numerador seja positivo e o denominador negativo, o sinal de menor
		// apareça posicionado corretamente na impressão, ou seja, antes do numerador
		if(numerator >= 0 and denominator < 0){
			cout << (-1) * numerator << "/" << (-1) * denominator << " = ";
			cout << (-1) * numerator / mdc << "/" << (-1) * (denominator / mdc) << endl;
		}
		else{
			cout << numerator << "/" << denominator << " = ";
			cout << numerator / mdc << "/" << denominator / mdc << endl;
		}

	}
	return 0;
}
