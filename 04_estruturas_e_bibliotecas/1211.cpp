#include <bits/stdc++.h>
using namespace std;

void count_saved_char(vector<string> &instance){
	
	int saved_char = 0;
	
	for(int i = 1; i < instance.size(); i++){
		
		string num_1 = instance[i - 1];
		string num_2 = instance[i];

		/*
		aqui est� a ideia principal do algoritmo, que consiste passar um loop pelos dois valores adjascentes na lista,
		comparando cada caractere. Assim que um caractere diferente (na mesma posi��o de ambos) � encontrado, ent�o
		o loop � interrompido e aquela posi��o � contabilizado (incrementando o n�mero de espa�os economizados).
		A outra condi��o de parada do loop � quando todos os caracteres s�o iguais, nesse caso todas as posi��es do 
		valor s�o economizadas, j� que este � igual ao de cima.
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
		a ordena��o � necess�ria para garantir que haja compara��o dos n�meros com maior potencial de valores em comum na mesma posi��o
		OBS 1: Aqui n�o tem restri��es de ordena��o usando trocas adjacentes por exmeplo, como j� visto em outros problemas.
		Por isso est� sendo usado o pr�prio sort da linguagem.
		OBS 2: ser poss�vel a ordena��o de vetor de strings torna desnecess�ria a convers�o dos valores para inteiros, evitando os problemas
		que essa convers�o traria (exclus�o dos zeros � esquerda e falta de range pra converter inteiros extremamente grandes, com string n�o h� essa restri��o) 
		*/
		sort(instance.begin(), instance.end());
		
		count_saved_char(instance);
		
		// avan�ao para a pr�xima inst�ncia
		start_instance += n_tel_numbers + 1;
		if(start_instance < inputs.size()){
			n_tel_numbers = stoi(inputs[start_instance]);
		}
	}
	return 0;
}
