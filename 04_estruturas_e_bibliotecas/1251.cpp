#include <bits/stdc++.h>
using namespace std;

void double_bubble_sort(vector<char> &char_vec, vector<int> &freq_vec){

	/* 
	Nesse primeiro sort, há a ordenação do vetor de ferquência, e no momento que houver
	troca, é realizada a troca no vetor de strings também. Assim, quando o vetor de
	tamanhos estiver ordenado, o vetor de strings estará exatamente na mesma ordem.
	*/
    for(int i = 0; i < freq_vec.size(); ++i){
        for(int j = 0; j < freq_vec.size() - i - 1; ++j){
            if(freq_vec[j] > freq_vec[j + 1]){
                swap(freq_vec[j], freq_vec[j + 1]);
                swap(char_vec[j], char_vec[j + 1]);
            }
        }
    }
    /* 
	Já nesse segundo sort, depois dos vetores terem sido organizados de acordo com a
	frequência (em ordem crescente), aqui são analisados apenas aqueles elementos com
	FREQUÊNCIAS IGUAIS, e esses são ordenados apenas entre si, porém em ordem decrescente
	*/
    for(int i = 0; i < freq_vec.size(); ++i){
        for(int j = 0; j < freq_vec.size() - i - 1; ++j){
  
            if(char_vec[j] < char_vec[j + 1] and freq_vec[j] == freq_vec[j + 1]){
                swap(freq_vec[j], freq_vec[j + 1]);
                swap(char_vec[j], char_vec[j + 1]);
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
	
	for(int i = 0; i < inputs.size(); i++){
		string instance = inputs[i];
		// ordenação para já agrupar os caracteres
		sort(instance.begin(), instance.end());
		
		int counter = 0;
		char current_char = instance[0];
		
		vector <char> char_vec;
		vector <int> freq_vec;

		for(int j = 0; j < instance.size(); j++){
			char it_char = instance[j];
			if(current_char == it_char){
				counter++;
			}
			// a ideia é basicamente incrementar o contador até que um caractere diferente
			// seja encontrado, reinicializando-o e recomeçando a contagem
			else{
				char_vec.push_back(current_char);
				freq_vec.push_back(counter);
				counter = 1;
				current_char = it_char;
			}
		}
		//Passo importante! Aqui ocorre a adição da chave e da frequência do último
		// caractere, já que o loop faz essa adição antes de avançar para o próximo
		//caractere (para reinicializar o contador e atualizar a caractere atual).
		// Dessa forma o loop não adiciona a última ocorrência
		char_vec.push_back(current_char);
		freq_vec.push_back(counter);
		
		// ordenação crescente com base na frequência e descrecente
		// com base no valor ascii, daqueles com frequências iguais
		double_bubble_sort(char_vec, freq_vec);
		
		for(int k = 0; k < char_vec.size(); k++){
			int ascii_char = char_vec[k]; // para imprimir o valor na tabela ascii, não o caractere em si
        	cout << ascii_char << " " << freq_vec[k] << endl;
    	}
    	
    	if(i < inputs.size() - 1){
    		cout << endl;
		}
	}
	
	return 0;
}
