#include <bits/stdc++.h>
using namespace std;

int main(){
	
	// como ser� lido o nome do vendedor, aqui o vetor � de strings. A convers�o das componentes num�ricas para valor um
	// tipo num�rico ser� feita posteriormente
	vector<string> input;
    string line;
    
	while (getline(cin, line)){
        input.push_back(line);
    }
    
	string NOME = input[0];
	
	// OBS: j� tinha sido vista a fun��o stoi, que converte para inteiro.
	//stof: converte para float
	//stod: converte para double
	double SALARIO = stof(input[1]), VENDAS = stof(input[2]);
	double TOTAL = SALARIO + (VENDAS * 0.15);
	
	cout << fixed << setprecision(2);
	cout << "TOTAL = R$ " << TOTAL << endl;
	
	return 0;
}

