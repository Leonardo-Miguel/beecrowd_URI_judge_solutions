#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 1; i < inputs.size(); i++){
		string text =inputs[i];
		
		int cut = (text.size() / 2);
		int start = 0;
		int end = cut - 1;
		
		// basta usar um duplo swap, um que trabalha com a primeira e o outro com a segunda metade da palavra
		// usando o cut como parametro para a inversão de posições ele vai inverter somente uma das metades (e a outra separadamente à partir dele)
		while(start < end){
			swap(text[start], text[end]);
			swap(text[start + cut], text[end + cut]);
			start++;
			end--;
		}
		cout << text << endl;
	}
	return 0;
}
