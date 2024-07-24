#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 0; i < inputs.size(); i++){
		
		string user_input = inputs[i];
		string formatted_input;
		int error_char = 0;
		
		for(int j = 0; j < user_input.size(); j++){
			if(user_input[j] == 'O' or user_input[j] == 'o'){
				formatted_input += '0';
			}
			else if(user_input[j] == 'l'){
				formatted_input += '1';
			}
			else if(user_input[j] >= 48 and user_input[j] <= 57){
				formatted_input += user_input[j];
			}
			else if(user_input[j] == ',' or user_input[j] == ' '){
				formatted_input = formatted_input;
			}
			else{
				error_char = 1;
				break;	
			}
		}
		
		if(error_char == 1){
			cout << "error" << endl;
		}
		else{
			try {
        		cout << stoi(formatted_input) << endl;
	    	} catch (...) {
	        	cout << "error" << endl;
    		}
		}
		// tratamento de erro em c++. O (...) indica que entrará na exceção em qualquer erro.
		// no caso entra na exceção em 2 situações: maior valor que o range do um int (2147483647) e linha vazia
		// (o caso de outros caracteres já é tratado anteriormente, no if externo ao try-catch)
		// Em nenhum desse casos haverá uma string que possa ser convertida para inteiro

	}
	return 0;
}
