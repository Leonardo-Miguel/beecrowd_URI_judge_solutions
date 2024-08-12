#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 0; i < inputs.size() - 1; i++){
		
		string input = inputs[i];
	
		istringstream iss(input);
		int x1, y1, x2, y2;
		iss >> x1 >> y1 >> x2 >> y2;

		if(x1 == x2 and y1 == y2){
			cout << 0 << endl;
		}
		//verifica os movimentos paralelos
		else if((x1 == x2 and y1 != y2) or (x1 != x2 and y1 == y2)){
			cout << 1 << endl;
		}
		//verifica os movimentos diagonais
		else if(abs(x1 - x2) == abs(y1 - y2)){
			cout << 1 << endl;
		}
		else{
			cout << 2 << endl;
		}
	}
	
	return 0;
}
