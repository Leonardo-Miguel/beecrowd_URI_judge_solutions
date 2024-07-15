#include <bits/stdc++.h>

int main(){
	int A, B; // reparar adeclaração de mais de um variável ao mesmo tempo, e SEM VALOR ATRIBUÍDO. Como são do mesmo tipo (int), masta definir o tipo uma única vez
	
	//reparar que o >> é diferente do cout. Aqui a entrada digitada (cin) é passada para a varável, apontando para ela. Já no cout é o contrário, a variável que é passada para a saída
	std::cin >> A;
	std::cin >> B;
	
	// reparar que O CÁLCULO É FEITO DIRETO DENTRO DO COUT, ou seja, não precisa armazenar uma variável com o valor
	std::cout << "X = " << A + B << std::endl;
	
	return 0;
}
