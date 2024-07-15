#include <bits/stdc++.h>
using namespace std;

int main(){
	double A, B, C;
	cin >> A;
	cin >> B;
	cin >> C;
	
	const int weight_A = 2, weight_B = 3, weight_C = 5;
	double MEDIA = (A * weight_A + B * weight_B + C * weight_C) / (weight_A + weight_B + weight_C);
	
	cout << fixed << setprecision(1);
	cout << "MEDIA = " << MEDIA << endl;
	
	return 0;
}
