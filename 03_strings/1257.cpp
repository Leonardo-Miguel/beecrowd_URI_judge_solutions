#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	int n_instances = stoi(inputs[0]);
	int count_instances = 0;
	int N = stoi(inputs[1]);
	int start = 2;
	
	while(count_instances < n_instances){

		int hash_value = 0;
		int row_instance = 0;
		
		// para resolver o problema basta fazer dois loops aninhandos que percorram as linhas e colunas (letras de cada linha)
		// somando o valor da letra à sua posição (linha e coluna), sendo este o valor dessa letra na tabela. Com isso,
		// armazena-se o valor de cada letra da tabela daquela intância e acumula-se esses valores como valor total da isntância.
		for(int row = start; row < start + N; row++){
			string table_row = inputs[row];
			
			for(int col = 0; col < table_row.size(); col++){
				int letter = table_row[col] - 65;
				
				hash_value += (letter + col + row_instance);
			}
			row_instance += 1;
		}
		
		cout << hash_value << endl;
		
		// avanço para o próximo bloco.
		// O if é para que não haja tentativa de acessar uma intância à mais do que as existentes.
		if (count_instances < n_instances - 1){
			start += N + 1;
			N = stoi(inputs[start - 1]);
		}
		count_instances += 1;
	}

	return 0;
}
