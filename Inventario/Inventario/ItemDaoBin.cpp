#include "ItemDaoBin.h"

using namespace std;

ItemDaoBin::ItemDaoBin()
{
}


ItemDaoBin::~ItemDaoBin()
{
}

Item * ItemDaoBin::obtemTodosItens()
{
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
