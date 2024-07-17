#include <bits/stdc++.h>
using namespace std;

void verify_match(string str1, string str2){
	
	string answer = "nao encaixa";

	int verifier = 0;
	
	// caso a string 1 seja menor que a string 2 n�o faz sentido comparar, pois j� n�o encaixa
	if(str1.size() >= str2.size()){
		for(int j = 0; j < str2.size(); j++){
			// o importante de se eperceber � que �preciso percorrer as strings de tr�s pra frente (str.size() - j - 1), n�o h� necessidade de invert�-las
			if(str1[str1.size() - j - 1] == str2[str2.size() - j - 1]){
				verifier += 1;
			}
			else{
				// caso haja um unico caractere que n�o corresponda o loop � interrompido, pois j� n�o encaixa e n�o precisa continuar iterando
				if(str1[str1.size() - j - 1] != str2[str2.size() - j - 1]){
					break;
				}
			}
		}	
	}
	
	// caso a condi��o abaixo seja satisfeita � porque todas as caracteres da string 2 encaixaram, logo h� o encaixe
	if(verifier == str2.size()){
		answer = "encaixa";
	}
	
	cout << answer << endl;
}

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 1; i < inputs.size(); i++){
		
		string text = inputs[i];
		
		int sep_position = text.find(" ");
		
		string str1 = text.substr(0, sep_position);
		string str2 = text.substr(sep_position + 1);
		verify_match(str1, str2);
		
	}
	return 0;
}
