#pragma once
#include "Inventario.h"
class Personagem
{
public:
	Personagem();
	~Personagem();
	
	void recuperarVida();
	void coletaItem(Item * it);
	void guardaItens();
private:
	int vida;
	Inventario * inventario;

		
	
	
};

