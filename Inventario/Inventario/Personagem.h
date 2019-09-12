#pragma once
#include "Item.h"
#include "ItemDao.h"
#include "ItemDaoStream.h"

class Personagem
{
public:
	Personagem();
	~Personagem();
	Item * inventario;
	Item item_atual;
	
	void inserirItem(std::ostream & os);
	void inserirItemEm(std::ostream & os, int indice);
	void carregaItens(std::istream & is);
	int obtemQuantidadeItens();
private:
	int quantidade;

		
	
	
};

