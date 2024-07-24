#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string str, char delimiter){
	
	vector<string> sep_strings;

	int first_non_delimiter_index = 0;
	while(str[first_non_delimiter_index] == delimiter){
		first_non_delimiter_index++;
	}
	
	int i = first_non_delimiter_index, first_char = first_non_delimiter_index, last_char = first_non_delimiter_index;
	
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

void return_score(vector<string> splitted_text){
	
	int total_word_len = 0, total_words = 0;
	
	for(int j = 0; j < splitted_text.size(); j ++){
		
		string word = splitted_text[j];
		
		// para evitar palavras que sejam somente um ponto isolado
		if(word != "."){
			// o all_of é uma função que verifica se é uma condição é válida PARA TODOS OS CARACTERES DENTRO DO INTERVALO DE INTERESSE
			// (nesse caso até o pnultimo caractere, já que vai de str.begin à str.end - 1). A condição pode ser uma função definida ou nativa como o is alpha abaixo
			// o -1 é porque o último cacterer não será verificado ainda (já que a palavra ainda pode ser válida se este for um ponto final)
			bool all_letters = all_of(word.begin(), word.end() - 1, ::isalpha);
	
			bool last_letter = isalpha(word.back()); // o .back é usado para acessar a última caractere de uma string
			if(word[word.size() - 1] != '.' and  last_letter != 1){
				all_letters = 0;
			}
	
			if(all_letters == 1){
				int last_char = word.size();
				if(word[word.size() - 1] == '.'){
					last_char = word.size() - 1;
				}
				total_word_len += last_char;
				total_words++;
			}
		}
	}
	
	int mean = 0;
	// para evitar a divisão por zero
	if(total_words > 0){
		// IMPORTANTE! Como a variável mean já foi definida externamente ao if, não precisa declará-la de novo, somente mudar seu valor
		// tentar declará-la novamente com mesmo valor não é reconhecido
		mean = total_word_len / total_words;
	}
	
	if (mean <= 3) {
	    cout << 250 << endl;
	} else if (mean > 3 && mean <= 5) {
	    cout << 500 << endl;
	} else if (mean > 5) {
	    cout << 1000 << endl;
	}
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
    
	    // observar que a saída da função split_string é um vetor que guarda as strings 'splitadas', por isso para
		// acessar alguma em específico se utiliza do indice no vetor
		vector<string> splitted_text = split_string(text, delimiter);
		return_score(splitted_text);
			
	}
	return 0;
}
