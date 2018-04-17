#include <iostream>
#include "Exer1.h";
#include "Exer3.h";
using namespace std;
int main() {
	Exer1 e1;
	Exer3 e3;
	/*int N;
	cout << "Informe um Número" << endl;
	cin >> N;
	cout << "O Somatório do Número Informado é: " << e1.somatorio(N) << endl;
	*/
	e3.preencheVetor();
	e3.inverteVetor(5);
	e3.mostraVetores();
	system("pause");
	return 0;
}