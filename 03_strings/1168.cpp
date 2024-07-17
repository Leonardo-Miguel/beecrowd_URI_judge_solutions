#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<int> leds_per_digit = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; // o indice do vetor (posição de cada dígito) corresponderá ao próprio dígito, para auxiliar na comparação
	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 1; i < inputs.size(); i++){
		int n_leds = 0;
		for(int j = 0; j < inputs[i].size(); j++){
			string str_char(1, inputs[i][j]); // convertendo uma char (que é o tipo quando se pega um unico caractere de uma string) em string propriamente dita
			int digit = stoi(str_char); // agora sim a conversão da char (que agora é string) funciona usando o stoi
			n_leds += leds_per_digit[digit];		
		}
		cout << n_leds << " leds" << endl;
	}
	
	return 0;
}
