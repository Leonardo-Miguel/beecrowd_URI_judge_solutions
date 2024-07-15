#include <bits/stdc++.h>
using namespace std;

int main(){
	double A, B;
	cin >> A;
	cin >> B;
	
	const float weight_A = 3.5, weight_B = 7.5;
	double MEDIA = (A * weight_A + B * weight_B) / (weight_A + weight_B);

	cout << fixed << setprecision(5);
	cout << "MEDIA = " << MEDIA << endl;
	
	return 0;
}
