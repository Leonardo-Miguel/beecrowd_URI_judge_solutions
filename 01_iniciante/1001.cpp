#include <bits/stdc++.h>

int main(){
	int A, B; // reparar adeclara��o de mais de um vari�vel ao mesmo tempo, e SEM VALOR ATRIBU�DO. Como s�o do mesmo tipo (int), masta definir o tipo uma �nica vez
	
	//reparar que o >> � diferente do cout. Aqui a entrada digitada (cin) � passada para a var�vel, apontando para ela. J� no cout � o contr�rio, a vari�vel que � passada para a sa�da
	std::cin >> A;
	std::cin >> B;
	
	// reparar que O C�LCULO � FEITO DIRETO DENTRO DO COUT, ou seja, n�o precisa armazenar uma vari�vel com o valor
	std::cout << "X = " << A + B << std::endl;
	
	return 0;
}
