#pragma once
#include "Item.h"
class ItemDao
{
public:
	
	virtual Item * obtemTodosItens() = 0;
	virtual bool guardaTodosItens(Item * it_itens) = 0;
	
};

