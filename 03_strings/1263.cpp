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
		if(str[i] == delimiter or i == str.size()){
			last_char = i;
			string sub = str.substr(first_char, last_char - first_char);
			sep_strings.push_back(sub);
			first_char = last_char + 1;
		}
		i++;
	}
	
	return sep_strings;
}

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 0; i < inputs.size(); i++){
		
		string text = inputs[i];
		
		char delimiter = ' ';

		vector<string> splitted_text = split_string(text, delimiter);
		
		int alliterations = 0;
		int counter = 0;
		
		for(int j = 1; j < splitted_text.size(); j++){
			
			char previous_initial = splitted_text[j-1][0];
			char current_initial = splitted_text[j][0];
			
			// para que as iniciais maiúsculas sejam convertidas em minúsculas, garantindo a comparação
			
			if(previous_initial <= 90){
				previous_initial += 32;	
			}
			if(current_initial <= 90){
				current_initial += 32;	
			}
			
			/*
			estratégia: caso sejam encontradas duas palavras com a mesma inicial, o contador recebe valor 1 e é contada uma aliteração.
			Porém aqui vem o passo importante para que mais de duas palavras consecutivas com a mesma inicial NÃO SEJAM CONTADAS COMO MAIS
			DE UMA ALITERAÇÃO. No caso é adicionada aliteração SOMENTE SE O CONTADOR FOR ZERO, se ele for um, singifica que duas palavras
			anteriores naquela mesma sequência já somaram aquela aliteração. E no segundo if vem outro passo importante, caso as iniciais
			sejam diferentes, o contador é zerado novamente, para que a próxima aliteração seja devidamente considerada. 
			*/
			if(previous_initial == current_initial and counter == 0){
				counter = 1;
				alliterations += counter;
			}
			if(previous_initial != current_initial){
				counter = 0;
			}
		}
		
		cout << alliterations << endl;
			
	}
	return 0;
}
