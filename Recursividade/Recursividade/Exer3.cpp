#include "Exer3.h"



Exer3::Exer3()
{
}


Exer3::~Exer3()
{
}

void Exer3::inverteVetor(int indice)
{
	//condição de parada
	if (indice >= 0) {
		this->vetor_aux[this->TAM - (indice)] = this->vetor[indice-1];
		inverteVetor(indice - 1);
	}
	else
		return;
}

void Exer3::mostraVetores()
{
	for (int i = 0; i < this->TAM; i++)
		std::cout << vetor[i] << " ";
	std::cout << std::endl;
	for (int j = 0; j < this->TAM; j++)
		std::cout << vetor_aux[j] << " ";
}

void Exer3::preencheVetor()
{
	for (int i = 0; i < this->TAM; i++)
		std::cin >> this->vetor[i];
}
