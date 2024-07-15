#include <bits/stdc++.h>
using namespace std;

int main() {
	
    vector<float> input(3);

    for (int i = 0; i < input.size(); ++i) {
        cin >> input[i];
    }

    float NUMBER = input[0];
	float SALARY = input[1] * input[2];

	// OBS: como já visto, o fixed afeta apenas a forma como os números de ponto flutuante são formatados ao serem impressos, não seus valores em si
	// Por isso pode-se usar em locais diferentes, um para cada cout se assim se desejar, obtendo diferentes precisões
	
	cout << fixed << setprecision(0);
	cout << "NUMBER = " << NUMBER << endl;
	
	cout << fixed << setprecision(2);
    cout << "SALARY = U$ " << SALARY << endl;

    return 0;
}
