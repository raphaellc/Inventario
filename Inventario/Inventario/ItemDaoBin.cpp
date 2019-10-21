#include "ItemDaoBin.h"
#include <fstream>
using namespace std;

ItemDaoBin::ItemDaoBin()
{
}


ItemDaoBin::~ItemDaoBin()
{
}

Item * ItemDaoBin::obtemTodosItens()
{
	std::ifstream i_persiste;
	i_persiste.open("Inventario.bin", ios::binary | ios::in);
	if (!i_persiste.is_open())
	{
		return nullptr;
	}else
	{
		Item * itens = new Item[10];
		int i = 0;
		do{
			i_persiste.read(reinterpret_cast<char *>(&itens[i]), sizeof(Item));
			i++;
			
		} while (!i_persiste.eof());
	}
	return nullptr;
}

bool ItemDaoBin::guardaTodosItens(Item * it_itens)
{
	std::ofstream o_persiste("Inventario.bin", ios::binary | ios::out);
	if (!o_persiste.is_open()) {
		return false;
	}
	else {
		for (int i = 0; i < 10; i++) {
			if(it_itens[i].id >= 0)
				o_persiste.write(reinterpret_cast<char *>(&it_itens[i]), sizeof(Item));
		}
		return true;
	}

	return false;
}
