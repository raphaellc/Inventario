#pragma once
#include "Inventario.h"
class Personagem
{
public:
	Personagem();
	~Personagem();
	Inventario inventario;
	void recuperarVida();
private:
	int vida;

		
	
	
};

