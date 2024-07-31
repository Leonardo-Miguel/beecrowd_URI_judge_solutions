#include <bits/stdc++.h>
using namespace std;

/*
Vantagens de se usar um map (dict) no problema:
1) em c++ esses são AUTOMATICAMENTE ORDENADOS (ordem crescente) POR CHAVE, o que garante a ordem de consumo médio por residência
2) como chaves são únicas, caso haja outra casa com o mesmo consumo médio, os habitantes ão só adicionados, agrupando os ocnsumidores
com aquele sconsum médio. OBS: inclusive esse agrupamento é chave do problema, que pode ter menos grupos de consumo médio do que casas
*/
void calculate_avg_consumption(map<int, int> &consumption_map, int consumers, int consumption){

	// como é uma divisão entre inteiros, o resultado é automaticmanete inteiro
	int avg_consumption = consumption / consumers;

	auto iterator = consumption_map.find(avg_consumption);
	
    if (iterator != consumption_map.end()){
        consumption_map[avg_consumption] += consumers;
    } else {
        consumption_map[avg_consumption] = consumers;
    }
}

int main(){

	vector<string> inputs;
	string line;
	
	while(getline(cin, line)){
		inputs.push_back(line);
	}
	
	int start = 1;
	int N = stoi(inputs[0]);
	int city = 0;

	while(N > 0){
		
		city += 1;
		
		// criação de um map (dicionário em c++)
		map<int, int> consumption_map;
		
		float total_consumers = 0.0, total_consumption = 0.0;
		 	
		for(int i = start; i < start + N; i++){
			string house = inputs[i];
			
			// como é uma separação simples e de apenas duas strings não precisa da função
			//que separa strings, apenas identificar a posição do espaço e usar subtring para isso
			int sep_pos = house.find(" ");
			string house_consumers = house.substr(0,sep_pos);
			string house_consumption = house.substr(sep_pos+1);
			
			int consumers = stoi(house_consumers);
			int consumption = stoi(house_consumption);
			
			total_consumption += consumption;
			total_consumers += consumers;
			
			calculate_avg_consumption(consumption_map, consumers, consumption);
		}
		
		// à partir daqui é só formatação da impressão (o único cálculo é do consumo médio da cidade)
		cout << "Cidade# " << city << ":" << endl;
		
		/*
		Para exibir os consumos médios e número de consumidores por cada consumo.
		Aqui é usado um loop "range-based for", que itera sobre todos os elementos de um container.
		OBS: o const é porque um chave não é mutável, somente o value. 
		OBS2: pair é somente o NOME DADO á um item do map, e .first e .second é a maneira de ACESSAR CHAVE E VALOR
		*/
		for(pair<const int, int> &pair : consumption_map){
			cout << pair.second << "-" << pair.first << ' ';
		}
		cout << endl;
		
		float avg_consumption_city = total_consumption / total_consumers;
		
		// Os passos a seguir são para garantir o TRUNCAMENTO (não arredondamento) em duas casas decimais
		string avg_consumption_city_str = to_string(avg_consumption_city); //conversão do valor para string
		int dot_pos = avg_consumption_city_str.find('.');
		avg_consumption_city_str.erase(dot_pos + 3); // Truncamento da string, ou seja, apagando tudo que está à partiro do ponto desejado (dois valores depois do ponto decimal)

		cout << "Consumo medio: " << avg_consumption_city_str << " m3." << endl;
		
		if(city < N){
			cout << endl;
		}
		
		// avanço para a próxima cidade
		start += N + 1;
		N = stoi(inputs[start - 1]);
		
	}

	return 0;
}
