#include <bits/stdc++.h>
using namespace std;

int main(){
	
	// como será lido o nome do vendedor, aqui o vetor é de strings. A conversão das componentes numéricas para valor um
	// tipo numérico será feita posteriormente
	vector<string> input;
    string line;
    
	while (getline(cin, line)){
        input.push_back(line);
    }
    
	string NOME = input[0];
	
	// OBS: já tinha sido vista a função stoi, que converte para inteiro.
	//stof: converte para float
	//stod: converte para double
	double SALARIO = stof(input[1]), VENDAS = stof(input[2]);
	double TOTAL = SALARIO + (VENDAS * 0.15);
	
	cout << fixed << setprecision(2);
	cout << "TOTAL = R$ " << TOTAL << endl;
	
	return 0;
}

