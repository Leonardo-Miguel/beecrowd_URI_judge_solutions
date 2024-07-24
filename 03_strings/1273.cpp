#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	int start = 1;
	int N = stoi(inputs[0]);
	
	while(N > 0){

		// estratégia: usar a maior palavra para preencher as demais com o número de espaços necessário para terem o mesmo tamanho
		// e inserindo à direita (inícios de cada uma), pós a inserção estarão justificadas à direita
		int biggest = 0; 
		for(int i = start; i < start + N; i++){
			if(inputs[i].size() > biggest){
				biggest = inputs[i].size();
			}
		}
		
		for(int i = start; i < start + N; i++){
			
			int n_spaces_to_add = biggest - inputs[i].size();
			/*
			os 3 argumentos da função insert são:
			a) posição da inserção (desloca o restante dos elementos para a direita)
			b) número de inserções do caractere desejado
			c) qual o caractere a ser adicionado
			*/
			inputs[i].insert(0, n_spaces_to_add, ' ');
			cout << inputs[i] << endl;
	
		}
		// avanço para o próximo bloco de palavras
		start += N + 1;
		N = stoi(inputs[start - 1]);
		
		// OBS: deve-se garantir que não seja impressa uma linha vazia após o ultimo caso, senão não passa
		if(N > 0){
			cout << endl;
		}
		
	}

	return 0;
}
