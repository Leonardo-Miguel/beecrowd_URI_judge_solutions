#include <bits/stdc++.h>
using namespace std;

int main(){
	
	// Importante! Nesse exerc�cio precisa usar double, o float n�o ir� garantir a precis�o
	double R;
	cin >> R;
	
	const double pi = 3.14159;
	double volume_esfera = (4.0/3) * pi * pow(R, 3); // pow � a fun��o matem�tica que calcula a pot�ncia: pow(base, expoente)

	cout << fixed << setprecision(3);
	cout << "VOLUME = " << volume_esfera << endl;
	
	return 0;
}
