#include <bits/stdc++.h>
using namespace std;

void combining_strings(string str_1, string str_2){
	
	string composed_str;
	if(str_1.size() >= str_2.size()){
		for(int j = 0; j < str_2.size(); j++){
			composed_str += str_1[j];
			composed_str += str_2[j];
		}
		// esse if é para não tentar concatenar uma substring inexistente, pois caso os tamanhos das strings 1 e 2 sejam iguais, não há substring restante
		if(str_1.size() > str_2.size()){
			composed_str += str_1.substr(str_2.size());
		}
	}
	else{
		if(str_1.size() < str_2.size()){
			for(int j = 0; j < str_1.size(); j++){
				composed_str += str_1[j];
				composed_str += str_2[j];
			}
			composed_str += str_2.substr(str_1.size());
		}
	}
	cout << composed_str << endl;
}

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 1; i < inputs.size(); i++){
		string text = inputs[i];
		
		int sep_position = text.find(" ");
		
		string str_1 = text.substr(0, sep_position);
		string str_2 = text.substr(sep_position + 1);

		combining_strings(str_1, str_2);	
	}
	return 0;
}
