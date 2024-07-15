#include <bits/stdc++.h>
using namespace std;

int main(){

	/* IMPORTANTE! Observar que aqui os valores são DIRETAMENTE parseados, ou seja, à partir da entrada
	cada um é atribuído corretamente à uma variável. Poderia se usar o split, lendo como uma string,
	splitando-a e convertendo cada substring para valores numéricos, como já visto. Porém é muito menos prático se
	tratando de valores numéricos e diretamente formatados na entrada, como neste problema.
	*/
	double A, B, C;
    cin >> A >> B >> C;
	
	cout << fixed << setprecision(3);
	cout << "TRIANGULO: " << A * C / 2 << endl;
	cout << "CIRCULO: " <<  3.14159 * C * C << endl;
	cout << "TRAPEZIO: " << (A + B) * C / 2 << endl;
	cout << "QUADRADO: " << B * B << endl;
	cout << "RETANGULO: " << A * B << endl;
	
	return 0;
}
