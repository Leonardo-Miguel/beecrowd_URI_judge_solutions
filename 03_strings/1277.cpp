#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string str, char delimiter){
	
	vector<string> sep_strings;
	
	int first_non_delimiter_index = 0;
	while(str[first_non_delimiter_index] == delimiter){
		first_non_delimiter_index++;
	}
	
	int i = first_non_delimiter_index;
            int first_char = first_non_delimiter_index;
            int last_char = first_non_delimiter_index;

	while(i <= str.size()){
		if(str[i] == delimiter || i == str.size()){
			last_char = i;
			string sub = str.substr(first_char, last_char - first_char);
			sep_strings.push_back(sub);
			first_char = last_char + 1;
		}
		i++;
	}
	
	return sep_strings;
}

// o uso do & garante que o vetor absent_or_not seja diretamente incrementado, sem ser necessário fazer isso externamente
// conforme o resultado da saída da função
void show_absents(string current_student, string freq_current_student, vector<string> & absent_students){
	
	float considered_classes = 0, presences = 0;
	
	for(int j = 0; j < freq_current_student.size(); j++){
		if(freq_current_student[j] == 'P'){
			presences += 1;
			considered_classes += 1;
		}
		if(freq_current_student[j] == 'A'){
			considered_classes += 1;
			}
	}
	
	float percentage = presences / considered_classes;
	
	if(percentage < 0.75){
		absent_students.push_back(current_student);
	}
		
}

 
int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	int n_instances = stoi(inputs[0]);
	int count_instances = 0;
	int start_instance = 2;
	
	char delimiter = ' ';
	
	while(count_instances < n_instances){

		string students_intance = inputs[start_instance];
		string frequencies_instance = inputs[start_instance + 1];
		
		vector<string> students = split_string(students_intance, delimiter);
		vector<string> frequencies = split_string(frequencies_instance, delimiter);
		
		char students_delimiter = ' ';
		
		// vetor necessário para armazenar somente os estudantes com frequência insuficiente, de forma à garantir a impressão somente
		// do último daquela instância não haja um espaço após o nome do estudante. Somente os demais devem possui espaço, para separá-los uns dos outros
		vector<string> absent_students;
		 
		for(int i = 0; i < students.size(); i++){
			string current_student = students[i];
			string freq_current_student = frequencies[i];
			show_absents(current_student, freq_current_student, absent_students);
		}
		
		for(int k = 0; k < absent_students.size(); k++){
			// os condicionais abaixo é que garatem a impressão conrreta mencionada, ou seja, com espaços entre os estudantes mas sem espaço dpeois do último
			if(k < absent_students.size() - 1){
				cout << absent_students[k] << ' ';
			}
			else if(k == absent_students.size() - 1){
				cout << absent_students[k];
			}		
		}
			
		cout << endl;
		start_instance += 3;
		count_instances += 1;
	}

	return 0;
}
