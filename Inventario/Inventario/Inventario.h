#pragma once
#include "Item.h"
#include "ItemDao.h"
#include "ItemDaoBin.h"
#include "ItemDaoSeq.h"


class Inventario
{
public:
	Inventario();
	Inventario(int tipo_persistencia);
	Inventario(ItemDao* item_dao);
	~Inventario();
	int obtemQuantidadeItens();
	Item * pegarItem(int tipo_item);
	void adicionaItem(Item * it); //Adiciona item no vetor inventario
	bool salvaInventario();
	void defineItemDao(ItemDao* item_dao);
	bool obtemEstado();
private:
	ItemDao * i_item_dao;
	Item * inventario;
	int quantidade;
	bool salvo;
	

	
	
	
};

