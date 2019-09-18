#pragma once
#include "Item.h"

class Inventario
{
public:
	Inventario();
	Inventario(int tipo_persistencia);
	~Inventario();
	void gravarItem(std::ostream & os);
	void gravarItemEm(std::ostream & os, int indice);
	Item * carregaItens(std::istream & is);
	int obtemQuantidadeItens();
	Item pegarItem(int tipo_item);
	void adicionaItem(Item * it); //Adiciona item no vetor inventario
	void gravarItens();
private:
	Item inventario[10];
	ItemDAO i_item_dao;
	int quantidade;
	Item item_atual;
	Item * inv;
};

