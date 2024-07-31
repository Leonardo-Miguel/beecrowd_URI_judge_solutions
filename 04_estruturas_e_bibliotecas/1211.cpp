#include <bits/stdc++.h>
using namespace std;

void count_saved_char(vector<string> &instance){
	
	int saved_char = 0;
	
	for(int i = 1; i < instance.size(); i++){
		
		string num_1 = instance[i - 1];
		string num_2 = instance[i];

		/*
		aqui está a ideia principal do algoritmo, que consiste passar um loop pelos dois valores adjascentes na lista,
		comparando cada caractere. Assim que um caractere diferente (na mesma posição de ambos) é encontrado, então
		o loop é interrompido e aquela posição é contabilizado (incrementando o número de espaços economizados).
		A outra condição de parada do loop é quando todos os caracteres são iguais, nesse caso todas as posições do 
		valor são economizadas, já que este é igual ao de cima.
		*/
		for(int k = 0; k < num_1.size(); k++){
			if(k == num_1.size() - 1 and num_1[k] == num_2[k]){
				saved_char += (k + 1);
				break;
			}
			else if(num_1[k] != num_2[k]){
				saved_char += k;
				break;
			}
		}
	}
	cout << saved_char << endl;
	
}

		
int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	int start_instance = 0;
	int n_tel_numbers = stoi(inputs[start_instance]);
		
	while(start_instance < inputs.size()){

		int start_slice = start_instance + 1;
		int end_slice = start_slice + n_tel_numbers;
		vector<string> instance(inputs.begin() + start_slice, inputs.begin() + end_slice);
		
		/*
		a ordenação é necessária para garantir que haja comparação dos números com maior potencial de valores em comum na mesma posição
		OBS 1: Aqui não tem restrições de ordenação usando trocas adjacentes por exmeplo, como já visto em outros problemas.
		Por isso está sendo usado o próprio sort da linguagem.
		OBS 2: ser possível a ordenação de vetor de strings torna desnecessária a conversão dos valores para inteiros, evitando os problemas
		que essa conversão traria (exclusão dos zeros à esquerda e falta de range pra converter inteiros extremamente grandes, com string não há essa restrição) 
		*/
		sort(instance.begin(), instance.end());
		
		count_saved_char(instance);
		
		// avançao para a próxima instância
		start_instance += n_tel_numbers + 1;
		if(start_instance < inputs.size()){
			n_tel_numbers = stoi(inputs[start_instance]);
		}
	}
	return 0;
}
