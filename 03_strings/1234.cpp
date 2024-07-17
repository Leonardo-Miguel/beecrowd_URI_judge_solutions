#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 0; i < inputs.size(); i++){
		//vetor que guarda os indices de todas as caracteres da string, exceto os espaços 
		vector<int> indices_non_space;
		for(int j = 0; j < inputs[i].size(); j++){
			if(inputs[i][j] != 32){
				indices_non_space.push_back(j);
			}
		}
		
		// obtido o vetor com os indices das caracteres, basta definir a primeira como maiúscula e a alternar as demais entre minúsculo e maiúsculo
		for(int j = 0; j < indices_non_space.size(); j++){
			int line_i = indices_non_space[j];
			if(j % 2 == 0){
				if(inputs[i][line_i] >= 97 and inputs[i][line_i] <= 122){
					inputs[i][line_i] -= 32;
				}
			}
			else{
				if(inputs[i][line_i] >= 65 and inputs[i][line_i] <= 90){
					inputs[i][line_i] += 32;
				}
			}
		}	
		cout << inputs[i]<< endl;
	}
	return 0;
}
