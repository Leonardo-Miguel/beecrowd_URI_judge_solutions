#include <bits/stdc++.h>
using namespace std;

int main() {
	
	// importante! Ao se armazenar os valores lidos num vetor, posteriormente pode-se atribuir os valores desse vetor
	// � vari�veis, em vez de chamar o cin n vezes e atribuir cada uma dessas vezes. Dessa forma pode-se atribuir de uma �nica vez
	// OBS: reparar uqe aqui o vetor � declarado j� com seu tamanho, poderia
    vector<int> input(4);

	// uso de um loop para n�o ter que usar o cin n vezes, como vinha sendo feito at� ent�o, para problemas com poucas entradas
    for (int i = 0; i < input.size(); ++i) {
        cin >> input[i]; //adicionando cada linha lida ao vetor
    }

    int A = input[0], B = input[1], C = input[2], D = input[3];

    int DIFERENCA = (A * B) - (C * D);
    cout << "DIFERENCA = " << DIFERENCA << endl;

    return 0;
}

/*
Segunda forma de fazer. � semelhante � acima, por�m aqui as linhas s�o lidas como strings, depois armazenadas num VETOR DE STRINGS,
e ent�o convertidas para int com o stoi. Observar que aqui o vetor n�o � declarado com tamanho definido como primeira forma, este � vazio
e vai sendo incrmenetado com as entradas.

IMPORTANTE! COM ESSA FORMA DE LEITURA DEVE-SE FINALIZAR DA SEGUINTE FORMA:
ENTER, DEPOIS COM CTRL+Z (INDICA O FIM DA ENTRADA), E DEPOIS O ENTER NOVAMENTE PARA FINALIZER A EXECU��O

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
