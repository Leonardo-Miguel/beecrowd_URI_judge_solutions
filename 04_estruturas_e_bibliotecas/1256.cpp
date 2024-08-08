#include <bits/stdc++.h>
using namespace std;

/*
A resolução basicamente consiste em utilizar um dicionário em que as chaves são
os endereços, e cada chave guarda vetores como valor. Nesse caso cada endereço 
armazenará os diferentes elementos que apontam para esses endereços.
*/

vector<int> split_and_convert_string(string str, char delimiter){
	
	vector<int> sep_input;

	int first_non_delimiter_index = 0;
	while(str[first_non_delimiter_index] == delimiter){
		first_non_delimiter_index++;
	}
	
	int i = first_non_delimiter_index;
            int first_char = first_non_delimiter_index;
            int last_char = first_non_delimiter_index;
	
	while(i <= str.size()){
		if(str[i] == delimiter || i == str.size()){
			last_char = i;
			string sub = str.substr(first_char, last_char - first_char);
			int sub_int = stoi(sub);
			sep_input.push_back(sub_int);
			first_char = last_char + 1;
		}
		i++;
	}
	
	return sep_input;
}

	
int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 2; i < inputs.size(); i += 2){
		
		int basis_adress = stoi(inputs[i-1]);
		string instance = inputs[i];
		map<int, vector<int>> instance_map;
		
		//OBS: mesmo que na criação de cada par chave/valor, o vetor do valor seja criado
		// da mesma forma, ainda são CÓPIAS DIFERENTES, ou seja, pode-se manipulá-los
		// separadamente e sem que um interfira no outro (por exemplo adicionando elementos)
		for(int j = 0; j < basis_adress; j++){
			vector<int> value_vec;
			instance_map[j] = value_vec;
		}
		
		char delimiter = ' ';
		vector<int> sep_input = split_and_convert_string(instance, delimiter);
		
		for(int k = 0; k < sep_input.size(); k++){
			int element = sep_input[k];
			int key_adress = element % basis_adress;
			instance_map[key_adress].push_back(element) ;
		}
		
		for (pair<const int, vector<int>> &pair : instance_map) { // o const é necessário
        	cout << pair.first << ' ';
        	
        	for(int m = 0; m < pair.second.size(); m++){
        		cout << "-> "<< pair.second[m] << ' ';
			}
			cout << "-> \\" << endl; //como a barra invertida é caractere especial, deve-se usar \\ para imprimir uma única barra
    	}
    	if(i < inputs.size() - 2){
    		cout << endl;
		}
	}
	
	return 0;
}
