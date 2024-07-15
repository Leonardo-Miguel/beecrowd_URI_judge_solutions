#include <bits/stdc++.h>
using namespace std;

int main(){

	/* IMPORTANTE! Observar que aqui os valores são DIRETAMENTE parseados, ou seja, à partir da entrada
	cada um é atribuído corretamente à uma variável. Poderia se usar o split, lendo como uma string,
	splitando-a e convertendo cada substring para valores numéricos, como já visto. Porém é muito menos prático se
	tratando de valores numéricos e diretamente formatados na entrada, como neste problema.
	*/
	int A, B, C;
    cin >> A >> B >> C;
	
	int maiorAB = (A + B + abs(A-B)) / 2;
	int maior = (maiorAB + C + abs(maiorAB-C)) / 2;
	cout << maior << " eh o maior" << endl;
	
	return 0;
}
