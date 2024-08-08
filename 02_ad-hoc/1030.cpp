#include <bits/stdc++.h>
using namespace std;

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	for(int i = 1; i < inputs.size(); i++){
		
		string input = inputs[i];
	
		istringstream iss(input);
		int n_people, jump;
		iss >> n_people >> jump;

		vector<int> circle(n_people);
		iota(circle.begin(), circle.end(), 1);
	
		int pos = 0, jump_after_cicles = 0, new_pos = 0;
		
		while (circle.size() > 1) {
	        jump_after_cicles = (jump - 1) % circle.size(); // o -1 é porque em termos de índice (que começa em 0), o jump real precisa ser ajustado.
	        new_pos = (pos + jump_after_cicles) % circle.size();
	        circle.erase(circle.begin() + new_pos);
	        pos = new_pos % circle.size();
    	}

		cout << "Case " << i << ": " << circle[0] << endl;
			
	}
	
	return 0;
}
