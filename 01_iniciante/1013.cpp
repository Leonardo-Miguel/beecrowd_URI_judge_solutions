#include <bits/stdc++.h>
using namespace std;

int main(){

	/* IMPORTANTE! Observar que aqui os valores s�o DIRETAMENTE parseados, ou seja, � partir da entrada
	cada um � atribu�do corretamente � uma vari�vel. Poderia se usar o split, lendo como uma string,
	splitando-a e convertendo cada substring para valores num�ricos, como j� visto. Por�m � muito menos pr�tico se
	tratando de valores num�ricos e diretamente formatados na entrada, como neste problema.
	*/
	int A, B, C;
    cin >> A >> B >> C;
	
	int maiorAB = (A + B + abs(A-B)) / 2;
	int maior = (maiorAB + C + abs(maiorAB-C)) / 2;
	cout << maior << " eh o maior" << endl;
	
	return 0;
}
