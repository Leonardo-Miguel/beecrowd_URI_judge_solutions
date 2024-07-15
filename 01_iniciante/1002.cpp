#include <bits/stdc++.h>

//faz com que n�o seja necess�rio usar 'std::' antes de usar qualquer componente da biblioteca
// � um an�logo � import 'from std import cin, cout, etc...' se fosse em python
using namespace std;

/*
um namespace (espa�o de nomes) � um mecanismo que permite agrupar entidades, como classes, fun��es, vari�veis
e outros, sob um nome comum. Isso ajuda a organizar o c�digo e a evitar conflitos de nomes, especialmente em
projetos grandes ou em bibliotecas que podem ser usadas em diferentes projetos. Por exemplo, quando diferentes
partes de um programa ou diferentes bibliotecas usam os mesmos nomes para vari�veis ou fun��es, podem ocorrer
conflitos. Nesse caso namespaces ajudam a evitar esse conflitos. por exemplo, as fun��es utilizadas no bloco
de c�digo abaixo s�o pertencentes ao std, por�m se fosse utilizada outra, basta usar 'using namespace outra
namespace' e passar para o seguinte bloco de c�digo utilizando-a.
*/

int main(){
	// reparar que mesmo sendo constante deve-se especificar o tipo. Se fosse 'int' ali, ele desconsideraria as casas decimais
	const double n = 3.14159;
	
	double raio;
	cin >> raio;

	// reparar que aqui a vari�vel �rea j� foi DECLARADA COM ATRIBUI��O DE UMA OPERA��O
	// anteriormente vimos que o resultado de uma opera��o nem precisa ser armazenado, pode s� ser exibido
	double area = n * raio * raio;
	
	// para especificar a precis�o da sa�da. REPARAR QUE EST� MUDANDO S� A SA�DA, N�O O VALOR DA VARI�VEL EM SI, S� A PRECIS�O
	// OBS: a precis�o default do fixed � 6 casas decimais. 
	cout << fixed << setprecision(4); 
	cout << "A=" << area << endl;
	
	return 0;
}

/*
Pode-se utilizar das 3 formas abaixo, por�m a 2 (utilizada aqui) � mais recomendada
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

