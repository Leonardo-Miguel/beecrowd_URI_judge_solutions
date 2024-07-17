#include <bits/stdc++.h>
using namespace std;

void verify_match(string str1, string str2){
	
	string answer = "nao encaixa";

	int verifier = 0;
	
	// caso a string 1 seja menor que a string 2 não faz sentido comparar, pois já não encaixa
	if(str1.size() >= str2.size()){
		for(int j = 0; j < str2.size(); j++){
			// o importante de se eperceber é que épreciso percorrer as strings de trás pra frente (str.size() - j - 1), não há necessidade de invertê-las
			if(str1[str1.size() - j - 1] == str2[str2.size() - j - 1]){
				verifier += 1;
			}
			else{
				// caso haja um unico caractere que não corresponda o loop é interrompido, pois já não encaixa e não precisa continuar iterando
				if(str1[str1.size() - j - 1] != str2[str2.size() - j - 1]){
					break;
				}
			}
		}	
	}
	
	// caso a condição abaixo seja satisfeita é porque todas as caracteres da string 2 encaixaram, logo há o encaixe
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
