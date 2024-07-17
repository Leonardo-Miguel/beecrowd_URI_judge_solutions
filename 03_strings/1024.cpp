#include <bits/stdc++.h>
using namespace std;

vector<int> encode(string str){
	
	vector<int> chars_converted_to_decimal;
	
	for(int i = 0; i < str.size(); i++){
		// o static_cast é para conversões de tipo explícitas, nesse caso de char para int (que retorna o valor na tabela ascii).
		// OBS: não confundir com o stoi, que converte a string para o número que é aquela string, aqui é por valor na tabela asc
		int ascii_value = static_cast<int>(str[i]);
		chars_converted_to_decimal.push_back(ascii_value);
	}
	
	return chars_converted_to_decimal;
	
}

//OBS: o parâmetro é passado com referência ao vetor original (chars_converted_to_decimal), o que indica que as alterações serão feitas in place
// Por isso a função PODE RETORNAR VOID, POIS O VETOR JÁ É MODOFICADO, AO SER PASSADO PARA OUTRA FUNÇÃO ELE JÁ ESTARÁ MODIFCADO POR ESSA
void first_pass(vector<int>&chars_converted_to_decimal){
	
	for(int i = 0; i < chars_converted_to_decimal.size(); i++){
		if((chars_converted_to_decimal[i] >= 65 && chars_converted_to_decimal[i] <= 90) ||
			(chars_converted_to_decimal[i] >= 97 && chars_converted_to_decimal[i] <= 122)){
			chars_converted_to_decimal[i] = chars_converted_to_decimal[i] + 3; // soma in place, ou seja, não precisa criar um outro vetor para modificar o valor daquela posição
		}
	}
}

void second_pass(vector<int>&chars_converted_to_decimal){
    int start = 0;
    int end = chars_converted_to_decimal.size() - 1;

	// invertendo o vetor in place. OBS: caso tenha número ímpar de elementos, o do meio não é visitado (devido ao stard ter que ser menor ao end, não menor ou igual)
    while (start < end) {
        std::swap(chars_converted_to_decimal[start], chars_converted_to_decimal[end]);
        start++;
        end--;
    }
}

void third_pass(vector<int>&chars_converted_to_decimal){
    int cut = chars_converted_to_decimal.size() / 2;
    
    // inicio do loop em 1 para não pegar o numero de instancias (primeira linha da entrada)
    for(int i = cut; i < chars_converted_to_decimal.size(); i++){
    	chars_converted_to_decimal[i] = chars_converted_to_decimal[i] - 1;
	}
}

void show_coded_string(vector<int>&chars_converted_to_decimal){
	string coded_string;
	for(int i = 0; i < chars_converted_to_decimal.size(); i++){
    	char reconverted_char = static_cast<char>(chars_converted_to_decimal[i]); //reconvertendo para char, de acordo com a tabela ascii
		coded_string += reconverted_char;
	}
	cout << coded_string << endl;
}

int main(){

	vector<string> inputs;
	string text;
	
	while(getline(cin, text)){
		inputs.push_back(text);
	}
	
	for(int i = 1; i < inputs.size(); i++){
		string str = inputs[i];
		vector<int> chars_converted_to_decimal = encode(str);
		first_pass(chars_converted_to_decimal); //obs: como já mecionado na definição da função first pass, não precisa que ela retorne o vetor e esse seja atribuído à um novo, é tudo in place
		second_pass(chars_converted_to_decimal);
		third_pass(chars_converted_to_decimal);
		show_coded_string(chars_converted_to_decimal);
	}
	
	return 0;
}
