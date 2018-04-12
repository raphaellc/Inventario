#pragma once
#include "Item.h";

class Personagem
{
public:
	Personagem();
	~Personagem();
	//Item * inventario[];
	Item item_atual;
	void inserirItem(std::ostream & os);
	void inserirItemEm(std::ostream & os, int indice);
	
};

