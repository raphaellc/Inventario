#include "Inventario.h"
#include <fstream>


Inventario::Inventario()
{
	std::ifstream leItem;
	leItem.open("Inventario.bin", std::ios::binary | std::ios::in);
	if (leItem.is_open()) {
		inv = carregaItens(leItem);
		for (int j = 1; j < 10; j++)
		{
			
		}
			
	}
}

Inventario::Inventario(int tipo_persistencia)
{
	if(tipo_persistencia == 1){
		i_item_dao = new ItemDAOImplBin();
	}
	else {
		i_item_dao = new ItemDAOImplSeq();
	}
}


Inventario::~Inventario()
{
}
void Inventario::gravarItem(std::ostream & os)
{
	os.write((char*) &item_atual, sizeof(Item));
	quantidade++;
}

void Inventario::gravarItemEm(std::ostream & os, int indice)
{
	std::streampos pos(indice * sizeof(Item));
	os.seekp(pos);
	std::cout << "O item ser� escrito na posi��o: " << os.tellp() << std::endl;
	os.write((char*)&item_atual, sizeof(Item));
	quantidade++;
}

Item * Inventario::carregaItens(std::istream & is)
{
	inv = i_item_dao->obtemTodosItens();
	Item * vetor = new Item[10];
	int indice = 0;
	while (!is.eof()){

		is.read(reinterpret_cast<char *>(&vetor[indice]), sizeof(Item));
		if (is.gcount() == 0) break;
		std::cout << "Id: " << inventario[indice].id << "Peso: " << inventario[indice].peso << "Tipo: " << inventario[indice].tipo << std::endl;
		indice++;

	}
	return vetor;
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

void Inventario::gravarItens()
{
}
