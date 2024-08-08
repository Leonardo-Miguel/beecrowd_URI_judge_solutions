#include <bits/stdc++.h>
using namespace std;

void double_bubble_sort(vector<char> &char_vec, vector<int> &freq_vec){

	/* 
	Nesse primeiro sort, h� a ordena��o do vetor de ferqu�ncia, e no momento que houver
	troca, � realizada a troca no vetor de strings tamb�m. Assim, quando o vetor de
	tamanhos estiver ordenado, o vetor de strings estar� exatamente na mesma ordem.
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
	J� nesse segundo sort, depois dos vetores terem sido organizados de acordo com a
	frequ�ncia (em ordem crescente), aqui s�o analisados apenas aqueles elementos com
	FREQU�NCIAS IGUAIS, e esses s�o ordenados apenas entre si, por�m em ordem decrescente
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
		// ordena��o para j� agrupar os caracteres
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
			// a ideia � basicamente incrementar o contador at� que um caractere diferente
			// seja encontrado, reinicializando-o e recome�ando a contagem
			else{
				char_vec.push_back(current_char);
				freq_vec.push_back(counter);
				counter = 1;
				current_char = it_char;
			}
		}
		//Passo importante! Aqui ocorre a adi��o da chave e da frequ�ncia do �ltimo
		// caractere, j� que o loop faz essa adi��o antes de avan�ar para o pr�ximo
		//caractere (para reinicializar o contador e atualizar a caractere atual).
		// Dessa forma o loop n�o adiciona a �ltima ocorr�ncia
		char_vec.push_back(current_char);
		freq_vec.push_back(counter);
		
		// ordena��o crescente com base na frequ�ncia e descrecente
		// com base no valor ascii, daqueles com frequ�ncias iguais
		double_bubble_sort(char_vec, freq_vec);
		
		for(int k = 0; k < char_vec.size(); k++){
			int ascii_char = char_vec[k]; // para imprimir o valor na tabela ascii, n�o o caractere em si
        	cout << ascii_char << " " << freq_vec[k] << endl;
    	}
    	
    	if(i < inputs.size() - 1){
    		cout << endl;
		}
	}
	
	return 0;
}
