#include <bits/stdc++.h>
using namespace std;

/*
A ideia é basicamente implementar um algoritmo de sort e contar o número de trocas
feitas.

IMPORTANTE! O bubble e o insertion sort realizam trocas somente de vizinhos diretos,
que é uma restrição do problema, logo são adequados.
*/

vector<int> split_input(string str, char delimiter){
	
	vector<int> sep_values;

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
			sep_values.push_back(stoi(sub)); // obs: para garantir que já haja a conversão de cada string em inteiro
			first_char = last_char + 1;
		}
		i++;
	}
	
	return sep_values;
}

void bubble_sort(vector<int> &sequence){
    int swaps = 0;

    for(int i = 0; i < sequence.size(); ++i){
        for(int j = 0; j < sequence.size() - i - 1; ++j){
            if(sequence[j] > sequence[j + 1]){
                swap(sequence[j], sequence[j + 1]);
                swaps++;
            }
        }
    }
    cout << "Optimal train swapping takes " << swaps << " swaps." << endl;
}
		
int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 2; i < inputs.size(); i+=2){
		char delimiter = ' ';
		vector<int> train = split_input(inputs[i], delimiter);
		bubble_sort(train);
	}
	
	return 0;
}
