#include "Inventario.h"



Inventario::Inventario()
{
}


Inventario::~Inventario()
{
}
void Inventario::inserirItem(std::ostream & os)
{
	os.write((char*)&item_atual, sizeof(Item));
	quantidade++;
}

void Inventario::inserirItemEm(std::ostream & os, int indice)
{
	std::streampos pos(indice * sizeof(Item));
	os.seekp(pos);
	std::cout << "O item ser� escrito na posi��o: " << os.tellp() << std::endl;
	os.write((char*)&item_atual, sizeof(Item));
	quantidade++;
}

void Inventario::carregaItens(std::istream & is)
{
	int indice = 0;
	while (!is.eof()) {

		is.read(reinterpret_cast<char *>(&inventario[indice]), sizeof(Item));
		/*if (is.gcount() == 0) break;
		std::cout << "Id: " << inventario[indice].id << "Peso: " << inventario[indice].peso << "Tipo: " << inventario[indice].tipo << std::endl;
		indice++;*/

	}
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
