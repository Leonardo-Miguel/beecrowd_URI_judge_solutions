#include <bits/stdc++.h>
using namespace std;

void queries_search(vector<int> marbles_vector, vector<int> queries_vector, int instance_number){
	
	cout << "CASE# " << instance_number << ":" << endl;
	
	for(int i = 0; i < queries_vector.size(); i++){
		int query = queries_vector[i];
		
		for(int j = 0; j < marbles_vector.size(); j++){
			if(query == marbles_vector[j]){
				cout << query << " found at " << j + 1 << endl;
				break;
			}
			if(j == marbles_vector.size() - 1 and query != marbles_vector[j]){
				cout << query << " not found" << endl;
			}
		}	
	}	
}

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	int start = 1;
	string init_instance = inputs[0];

	// uso do istringstream para parsear corretamente os valores e já obtê-los como inteiros
    istringstream iss(init_instance);
    int marbles, queries;
    iss >> marbles >> queries;
    
    int N = marbles + queries;
	int instance_number = 0;
	
	while(N > 0){
		
		instance_number += 1;
		
		// OBS: tomar cuidado para adicionar somente os mármores no vetor, não as consultas (valores a serem buscados)
		vector<int> marbles_vector;
		for(int i = start; i < start + marbles; i++){
			marbles_vector.push_back(stoi(inputs[i]));
		}
		// ordenação do vetor, para que a busca seja feita corretamente isso é necessário
		sort(marbles_vector.begin(), marbles_vector.end());
		
		// obs: esse não é ordenado, as saídas são dadas à medida que as consultas aparecem
		vector<int> queries_vector;
		for(int j = start + marbles; j < start + marbles + queries; j++){
			queries_vector.push_back(stoi(inputs[j]));
		}
		
		queries_search(marbles_vector, queries_vector, instance_number);
		
		// avanço para a próxima instância
		start += N + 1;
		init_instance = inputs[start-1];
	    istringstream iss(init_instance);
	    iss >> marbles >> queries;
		N = marbles + queries;
		
	}

	return 0;
}
