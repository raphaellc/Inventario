#include "Inventario.h"
#include <fstream>


Inventario::Inventario()
{
	
}

Inventario::Inventario(int tipo_persistencia)
{
	
}


Inventario::~Inventario()
{

}


int Inventario::obtemQuantidadeItens()
{
	return quantidade;
}

Item Inventario::pegarItem(int tipo_item)
{
	tipo_item = (TIPO_ITEM)tipo_item;
	if (quantidade == 0)
		return Item();
	for (int i; i < quantidade; i++)
		if (tipo_item == inventario[i].tipo)
			return inventario[i];
}

void Inventario::adicionaItem(Item * it)
{
	if (it != nullptr && quantidade < 10)
	{
		inventario[quantidade - 1] = * it;
		quantidade++;
	}
}
