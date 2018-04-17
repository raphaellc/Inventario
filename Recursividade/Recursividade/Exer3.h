#pragma once
#include <iostream>
class Exer3
{
public:
	Exer3();
	~Exer3();
	void inverteVetor(int indice);
	void mostraVetores();
	void preencheVetor();
	static const int TAM = 5;
	float vetor[TAM];
	float vetor_aux[TAM];
	
};

