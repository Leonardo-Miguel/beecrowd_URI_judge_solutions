#include <bits/stdc++.h>
using namespace std;

/*
O algoritmo basicamente empilha os '<' encontrados, e quando um aparece '>', formando um diamante,
então um '<' é desempilhado. Enquanto houver pares, ou seja, haverem '<' na pilha e um '>' ser 
encontrado, novos diamantes são contabilizados. Caso seja encontrado um '>' e a pilha esteja vazia,
significa que o par para aquele '>' não existe e não há contabilização. O processo continua até que
toda a entrada tenha sido percorrida.
*/

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 1; i < inputs.size(); i++){
		
		string instance = inputs[i];
		int diamonds = 0;
		
		vector<char> half_diamonds;
		
		for(int j = 0; j < instance.size(); j++){
			if(instance[j] == '<'){
				half_diamonds.push_back(instance[j]);
			}
			else if(instance[j] == '>' and half_diamonds.size() > 0){
				diamonds++;
				half_diamonds.pop_back();
			}
		}
		cout << diamonds << endl;
	}
	return 0;
}
