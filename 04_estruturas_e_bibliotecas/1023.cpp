#include <bits/stdc++.h>
using namespace std;

/*
Vantagens de se usar um map (dict) no problema:
1) em c++ esses s�o AUTOMATICAMENTE ORDENADOS (ordem crescente) POR CHAVE, o que garante a ordem de consumo m�dio por resid�ncia
2) como chaves s�o �nicas, caso haja outra casa com o mesmo consumo m�dio, os habitantes �o s� adicionados, agrupando os ocnsumidores
com aquele sconsum m�dio. OBS: inclusive esse agrupamento � chave do problema, que pode ter menos grupos de consumo m�dio do que casas
*/
void calculate_avg_consumption(map<int, int> &consumption_map, int consumers, int consumption){

	// como � uma divis�o entre inteiros, o resultado � automaticmanete inteiro
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
		
		// cria��o de um map (dicion�rio em c++)
		map<int, int> consumption_map;
		
		float total_consumers = 0.0, total_consumption = 0.0;
		 	
		for(int i = start; i < start + N; i++){
			string house = inputs[i];
			
			// como � uma separa��o simples e de apenas duas strings n�o precisa da fun��o
			//que separa strings, apenas identificar a posi��o do espa�o e usar subtring para isso
			int sep_pos = house.find(" ");
			string house_consumers = house.substr(0,sep_pos);
			string house_consumption = house.substr(sep_pos+1);
			
			int consumers = stoi(house_consumers);
			int consumption = stoi(house_consumption);
			
			total_consumption += consumption;
			total_consumers += consumers;
			
			calculate_avg_consumption(consumption_map, consumers, consumption);
		}
		
		// � partir daqui � s� formata��o da impress�o (o �nico c�lculo � do consumo m�dio da cidade)
		cout << "Cidade# " << city << ":" << endl;
		
		/*
		Para exibir os consumos m�dios e n�mero de consumidores por cada consumo.
		Aqui � usado um loop "range-based for", que itera sobre todos os elementos de um container.
		OBS: o const � porque um chave n�o � mut�vel, somente o value. 
		OBS2: pair � somente o NOME DADO � um item do map, e .first e .second � a maneira de ACESSAR CHAVE E VALOR
		*/
		for(pair<const int, int> &pair : consumption_map){
			cout << pair.second << "-" << pair.first << ' ';
		}
		cout << endl;
		
		float avg_consumption_city = total_consumption / total_consumers;
		
		// Os passos a seguir s�o para garantir o TRUNCAMENTO (n�o arredondamento) em duas casas decimais
		string avg_consumption_city_str = to_string(avg_consumption_city); //convers�o do valor para string
		int dot_pos = avg_consumption_city_str.find('.');
		avg_consumption_city_str.erase(dot_pos + 3); // Truncamento da string, ou seja, apagando tudo que est� � partiro do ponto desejado (dois valores depois do ponto decimal)

		cout << "Consumo medio: " << avg_consumption_city_str << " m3." << endl;
		
		if(city < N){
			cout << endl;
		}
		
		// avan�o para a pr�xima cidade
		start += N + 1;
		N = stoi(inputs[start - 1]);
		
	}

	return 0;
}
