#pragma once
#include "Inventario.h"
class Personagem
{
public:
	Personagem();
	~Personagem();
	
	void recuperarVida();
	void coletaItem(Item * it);
private:
	int vida;
	Inventario * inventario;

		
	
	
};

