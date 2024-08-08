#include <bits/stdc++.h>
using namespace std;
	
int main(){

	vector<int> even;
	vector<int> odd;
	string line;
	
    if (getline(cin, line)) {
        // Aqui a primeira linha é lida e descartada
        // Esse passo é importante já que ela não será usada
    }
    
	while(getline(cin, line)){
		int int_line = stoi(line);

		if(int_line % 2 == 0){
			even.push_back(int_line);
		}
		else{
			odd.push_back(int_line);	
		}
	}
	
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end(), greater<int>()); // Ordena em ordem decrescente
	
	for(int i = 0; i < even.size(); i++){
		cout << even[i] << endl;
	}
	
	for(int j = 0; j < odd.size(); j++){
		cout << odd[j] << endl;
	}
	
	return 0;
}
