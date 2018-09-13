#pragma once
#include "Item.h"
class ItemDao
{
public:
	
	virtual Item * obtemTodosItens() = 0;
	virtual bool guardaTodosItens(Item * it_itens) = 0;
	virtual void atualizaItem() = 0;
	virtual void deletaItem() = 0;
	virtual void adicionaItem() = 0;
};

