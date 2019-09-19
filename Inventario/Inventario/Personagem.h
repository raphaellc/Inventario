#pragma once
#include "Inventario.h"
class Personagem
{
public:
	Personagem();
	~Personagem();
	Inventario inventario;
	void recuperarVida();
	void coletaItem(Item * it);
private:
	int vida;

		
	
	
};

