#include <bits/stdc++.h>
using namespace std;

int main() {
	
    vector<float> input(3);

    for (int i = 0; i < input.size(); ++i) {
        cin >> input[i];
    }

    float NUMBER = input[0];
	float SALARY = input[1] * input[2];

	// OBS: como j� visto, o fixed afeta apenas a forma como os n�meros de ponto flutuante s�o formatados ao serem impressos, n�o seus valores em si
	// Por isso pode-se usar em locais diferentes, um para cada cout se assim se desejar, obtendo diferentes precis�es
	
	cout << fixed << setprecision(0);
	cout << "NUMBER = " << NUMBER << endl;
	
	cout << fixed << setprecision(2);
    cout << "SALARY = U$ " << SALARY << endl;

    return 0;
}
