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

		// estrat�gia: usar a maior palavra para preencher as demais com o n�mero de espa�os necess�rio para terem o mesmo tamanho
		// e inserindo � direita (in�cios de cada uma), p�s a inser��o estar�o justificadas � direita
		int biggest = 0; 
		for(int i = start; i < start + N; i++){
			if(inputs[i].size() > biggest){
				biggest = inputs[i].size();
			}
		}
		
		for(int i = start; i < start + N; i++){
			
			int n_spaces_to_add = biggest - inputs[i].size();
			/*
			os 3 argumentos da fun��o insert s�o:
			a) posi��o da inser��o (desloca o restante dos elementos para a direita)
			b) n�mero de inser��es do caractere desejado
			c) qual o caractere a ser adicionado
			*/
			inputs[i].insert(0, n_spaces_to_add, ' ');
			cout << inputs[i] << endl;
	
		}
		// avan�o para o pr�ximo bloco de palavras
		start += N + 1;
		N = stoi(inputs[start - 1]);
		
		// OBS: deve-se garantir que n�o seja impressa uma linha vazia ap�s o ultimo caso, sen�o n�o passa
		if(N > 0){
			cout << endl;
		}
		
	}

	return 0;
}
