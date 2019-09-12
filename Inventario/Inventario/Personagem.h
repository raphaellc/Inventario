#pragma once
#include "Item.h";

class Personagem
{
public:
	Personagem();
	~Personagem();
	Item inventario[10];
	Item item_atual;
	void inserirItem(std::ostream & os);
	void inserirItemEm(std::ostream & os, int indice);
	void carregaItens(std::istream & is);
	int obtemQuantidadeItens();
private:
	int quantidade;

		
	
	
};

