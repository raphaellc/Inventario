#include "Inventario.h"
#include <fstream>


Inventario::Inventario()
{
	quantidade = 0;
	this->inventario = new Item[10];
}

Inventario::Inventario(int tipo_persistencia)
{
	if (tipo_persistencia) {
		id_persistencia = new ItemDaoBin();
	}
	else {
		id_persistencia = new ItemDaoSeq();
	}
	
	this->inventario = id_persistencia->obtemTodosItens();
	if (this->inventario == nullptr) {
		this->inventario = new Item[10];
		quantidade = 0;
	}
	else{
	//Verifica Quantidade de Itens;
		for (int i = 0; i < 10; i++) {
			if (this->inventario[i].id > 0) {
				quantidade++;
			}
		}
	}
}


Inventario::~Inventario()
{

}


int Inventario::obtemQuantidadeItens()
{
	return quantidade;
}

Item * Inventario::pegarItem(int tipo_item)
{
	tipo_item = (TIPO_ITEM)tipo_item;
	if (quantidade == 0)
		return nullptr;
	for (int i=0; i < quantidade; i++)
		if (tipo_item == inventario[i].tipo)
			return &inventario[i];
	return nullptr;
}

void Inventario::adicionaItem(Item * it)
{
	if (it != nullptr && quantidade < 10)
	{
		inventario[quantidade] = * it;
		quantidade++;
	}
}
