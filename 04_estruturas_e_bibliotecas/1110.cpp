#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 0; i < inputs.size() - 1; i++){
		int n_cards = stoi(inputs[i]);
		
		vector<int> stack;
		for(int j = n_cards; j >= 1; j--){
			stack.push_back(j);
		}
		
		vector<int> discarded;

		while(stack.size() > 1){
			// o pop_back n�o retorna o elemento, por isso deve-se obt�-lo primeiro, separadamente
			int unstacked_card = stack.back();
	        stack.pop_back();
	        discarded.push_back(unstacked_card);
	        
	        // movendo a pr�xima carta para a base da pilha
	        int base_card = stack.back();
	        stack.pop_back();
	        stack.insert(stack.begin(), base_card); // obs: se a inser��o fosse em outra posi��o, deveria ser "stack.begin() + posi��o", n�o s� a posi��o
		}
		
		cout << "Discarded cards: ";
		for(int k = 0; k < discarded.size(); k++){
			if(k == discarded.size() - 1){
				cout << discarded[k] << endl;
			}
			else{
				cout << discarded[k] << ", ";
			}
			
		}
		cout << "Remaining card: " << stack[0] << endl;
	}

	return 0;
}
