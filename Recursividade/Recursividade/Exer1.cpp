#include "Exer1.h"



Exer1::Exer1()
{
}


Exer1::~Exer1()
{
}

int Exer1::somatorio(int N)
{
	if (N >= 1)
		return N + this->somatorio(N - 1);
	else
		return N;
}
