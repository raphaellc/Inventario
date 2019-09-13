#pragma once
#include "Item.h"

class Inventario
{
public:
	Inventario();
	~Inventario();
	void inserirItem(std::ostream & os);
	void inserirItemEm(std::ostream & os, int indice);
	void carregaItens(std::istream & is);
	int obtemQuantidadeItens();
	Item pegarItem(int tipo_item);
private:
	Item inventario[10];
	int quantidade;
	Item item_atual;
};

