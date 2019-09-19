#pragma once
#include "ItemDao.h"
class ItemDaoSeq :
	public ItemDao
{
public:
	ItemDaoSeq();
	~ItemDaoSeq();
	Item * obtemTodosItens() override;
	bool guardaTodosItens(Item * it_itens) override;
};

