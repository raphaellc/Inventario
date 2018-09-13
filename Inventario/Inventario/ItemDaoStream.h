#pragma once
#include "ItemDao.h"
#include <iostream>
#include <fstream>
#include <string>
class ItemDaoStream :
	public ItemDao
{
public:
	ItemDaoStream();
	~ItemDaoStream();
	Item * obtemTodosItens() override;
	bool guardaTodosItens(Item * it_itens) override;
	void atualizaItem() override;
	void deletaItem() override;
	void adicionaItem() override;
private:
	std::ifstream if_stream;
	std::ofstream of_stream;
};

