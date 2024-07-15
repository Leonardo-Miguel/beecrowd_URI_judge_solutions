#include <bits/stdc++.h>
using namespace std;

int main(){
	
	// Importante! Nesse exercício precisa usar double, o float não irá garantir a precisão
	double R;
	cin >> R;
	
	const double pi = 3.14159;
	double volume_esfera = (4.0/3) * pi * pow(R, 3); // pow é a função matemática que calcula a potência: pow(base, expoente)

	cout << fixed << setprecision(3);
	cout << "VOLUME = " << volume_esfera << endl;
	
	return 0;
}
