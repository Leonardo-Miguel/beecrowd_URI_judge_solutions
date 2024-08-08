#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string str, char delimiter){
	
	vector<string> sep_strings;

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
			sep_strings.push_back(sub);
			first_char = last_char + 1;
		}
		i++;
	}
	
	return sep_strings;
}


void bubble_sort(vector<string> &instance, vector<int> &instance_sizes){

    for(int i = 0; i < instance_sizes.size(); ++i){
        for(int j = 0; j < instance_sizes.size() - i - 1; ++j){
            if(instance_sizes[j] < instance_sizes[j + 1]){
            	/* aqui é a ideia chave: ordenar o vetor de tamanhos, e no momento que houver troca,
				é realizada a troca no vetor de strings também. Assim, quando o vetor de tamanhos
				estiver ordenado, o vetor de strings estará exatamente na mesma ordem
            	*/
                swap(instance_sizes[j], instance_sizes[j + 1]);
                swap(instance[j], instance[j + 1]);
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
	
	for(int i = 1; i < inputs.size(); i++){
		char delimiter = ' ';
		vector<string> instance = split_string(inputs[i], delimiter);
		
		vector<int> instance_sizes;
		for(int j = 0; j < instance.size(); j++){ 
			instance_sizes.push_back(instance[j].size());
		}
		
		bubble_sort(instance, instance_sizes);
		
		for(int k = 0; k < instance.size() - 1; k++){
			cout << instance[k] << ' ';
		}
		cout << instance[instance.size() - 1] << endl;
	}
	
	return 0;
}
