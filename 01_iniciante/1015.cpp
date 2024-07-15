#include <bits/stdc++.h>
using namespace std;

int main(){
	float x1, y1, x2, y2;
	
	// IMPORTANTE! Reparar que aqui, mesmo a entrada SENDO DUAS LINHAS, o parseamente ainda é feito corretamente
	// ou seja, a primeira é passada para o primeiro cin, e a segunda passada para o segundo
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    
	float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	
	cout << fixed << setprecision(4);
	cout << dist << endl;
	
	return 0;
}
