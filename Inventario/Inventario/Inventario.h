#pragma once
#include "Item.h"

class Inventario
{
public:
	Inventario();
	Inventario(int tipo_persistencia);
	~Inventario();
	int obtemQuantidadeItens();
	Item * pegarItem(int tipo_item);
	void adicionaItem(Item * it); //Adiciona item no vetor inventario
private:
	Item * inventario;
	int quantidade;
	
	
	
};

