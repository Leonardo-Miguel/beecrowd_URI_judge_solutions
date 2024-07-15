#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string str, char delimiter){
	
	vector<string> sep_strings;
	
	int i = 0, first_char = 0, last_char = 0;
	
	// o loop percorre a string buscando o delimitador, e assim que este é encontrado, o mesmo pega a substring que
	// está entre ele (last_char) e o delimitador (first_char). Assim que a substring é obtida, o first_char recebe o last_char,
	// para assim delimitar a próxima substring à partir dele, evitando sobreposições.
	while(i <= str.size()){
		if(str[i] == delimiter || i == str.size()){//OBS: ao pegar somente um caractere da string, ela é do tipo char, ppois isso delimiter precisar ser char
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
	
	vector<string> input;
    string line;
    
	while(getline(cin, line)){
        input.push_back(line);
    }
    
    char delimiter = ' '; // precisa ser char, pois será comparada à uma char (uma unica carctere de uma string)
    
    // observar que a saída da fnução split_string é um vetor com as strings 'splitadas', por isso para
	// acessar alguma em específico se utiliza do indice no vetor
	vector<string> peca_1 = split_string(input[0], delimiter);
	vector<string> peca_2 = split_string(input[1], delimiter);
	
	float valor_peca_1 = stof(peca_1[1]) * stof(peca_1[2]);
	float valor_peca_2 = stof(peca_2[1]) * stof(peca_2[2]);

	cout << fixed << setprecision(2);
	cout << "VALOR A PAGAR: R$ " << valor_peca_1 + valor_peca_2 << endl;

	return 0;
}

