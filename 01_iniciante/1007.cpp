#include <bits/stdc++.h>
using namespace std;

int main() {
	
	// importante! Ao se armazenar os valores lidos num vetor, posteriormente pode-se atribuir os valores desse vetor
	// à variáveis, em vez de chamar o cin n vezes e atribuir cada uma dessas vezes. Dessa forma pode-se atribuir de uma única vez
	// OBS: reparar uqe aqui o vetor é declarado já com seu tamanho, poderia
    vector<int> input(4);

	// uso de um loop para não ter que usar o cin n vezes, como vinha sendo feito até então, para problemas com poucas entradas
    for (int i = 0; i < input.size(); ++i) {
        cin >> input[i]; //adicionando cada linha lida ao vetor
    }

    int A = input[0], B = input[1], C = input[2], D = input[3];

    int DIFERENCA = (A * B) - (C * D);
    cout << "DIFERENCA = " << DIFERENCA << endl;

    return 0;
}

/*
Segunda forma de fazer. É semelhante à acima, porém aqui as linhas são lidas como strings, depois armazenadas num VETOR DE STRINGS,
e então convertidas para int com o stoi. Observar que aqui o vetor não é declarado com tamanho definido como primeira forma, este é vazio
e vai sendo incrmenetado com as entradas.

IMPORTANTE! COM ESSA FORMA DE LEITURA DEVE-SE FINALIZAR DA SEGUINTE FORMA:
ENTER, DEPOIS COM CTRL+Z (INDICA O FIM DA ENTRADA), E DEPOIS O ENTER NOVAMENTE PARA FINALIZER A EXECUÇÃO

int main(){
	
	vector<string> input;
    string line;
    
	while (getline(cin, line)){
        input.push_back(line);
    }
    
	int A = stoi(input[0]), B = stoi(input[1]), C = stoi(input[2]), D = stoi(input[3]);

	int DIFERENCA = (A * B) - (C * D);
	cout << "DIFERENCA = " << DIFERENCA << endl;
	
	return 0;
}
*/
