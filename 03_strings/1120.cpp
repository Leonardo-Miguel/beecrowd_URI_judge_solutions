#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 0; i < inputs.size(); i++){
		char broken_key = inputs[i][0]; // como é sempre uma única tecla quebra, não precisa de sustring, somente pegar o valor da primeira caractere da string
		string real_value = inputs[i].substr(2);
		string typed_value;
		 
		for(int j = 0; j < real_value.size(); j++){
			if (real_value[j] != broken_key){
				typed_value += real_value[j];
			}
		}
		
		// verifica se a string não está vazia (ou seja, se após a retirada da caractere inválida ainda possui algum caractere)
		if(typed_value.empty() == 0){
			cout << stoull(typed_value) << endl; //stoull converte para usigned long long int, ou seja, para garantir valores muitos altos
		}
	}
	
	return 0;
}
