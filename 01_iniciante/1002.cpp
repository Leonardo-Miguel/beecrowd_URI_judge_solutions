#include <bits/stdc++.h>

//faz com que não seja necessário usar 'std::' antes de usar qualquer componente da biblioteca
// é um análogo à import 'from std import cin, cout, etc...' se fosse em python
using namespace std;

/*
um namespace (espaço de nomes) é um mecanismo que permite agrupar entidades, como classes, funções, variáveis
e outros, sob um nome comum. Isso ajuda a organizar o código e a evitar conflitos de nomes, especialmente em
projetos grandes ou em bibliotecas que podem ser usadas em diferentes projetos. Por exemplo, quando diferentes
partes de um programa ou diferentes bibliotecas usam os mesmos nomes para variáveis ou funções, podem ocorrer
conflitos. Nesse caso namespaces ajudam a evitar esse conflitos. por exemplo, as funções utilizadas no bloco
de código abaixo são pertencentes ao std, porém se fosse utilizada outra, basta usar 'using namespace outra
namespace' e passar para o seguinte bloco de código utilizando-a.
*/

int main(){
	// reparar que mesmo sendo constante deve-se especificar o tipo. Se fosse 'int' ali, ele desconsideraria as casas decimais
	const double n = 3.14159;
	
	double raio;
	cin >> raio;

	// reparar que aqui a variável área já foi DECLARADA COM ATRIBUIÇÃO DE UMA OPERAÇÃO
	// anteriormente vimos que o resultado de uma operação nem precisa ser armazenado, pode só ser exibido
	double area = n * raio * raio;
	
	// para especificar a precisão da saída. REPARAR QUE ESTÁ MUDANDO SÓ A SAÍDA, NÃO O VALOR DA VARIÁVEL EM SI, SÓ A PRECISÃO
	// OBS: a precisão default do fixed é 6 casas decimais. 
	cout << fixed << setprecision(4); 
	cout << "A=" << area << endl;
	
	return 0;
}

/*
Pode-se utilizar das 3 formas abaixo, porém a 2 (utilizada aqui) é mais recomendada
1) 
double area;
area = n * raio * raio;
cout << area;
2)
double area = n * raio * raio;
cout << area;
3)
cout << n * raio * raio;
*/

