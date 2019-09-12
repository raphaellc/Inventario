#include "ItemDaoStream.h"



ItemDaoStream::ItemDaoStream()
{
}


ItemDaoStream::~ItemDaoStream()
{
}

Item * ItemDaoStream::obtemTodosItens() {
	auto inventario = new Item[10];
	this->if_stream.open("Inventario.bin", std::ios::binary | std::ios::in);
	if(!this->if_stream){
		return nullptr;
	}else{
		int indice = 0;
		while (!this->if_stream.eof()) {

			if_stream.read(reinterpret_cast<char *>(&inventario[indice]), sizeof(Item));
			if (if_stream.gcount() == 0) break;
			std::cout << "Id: " << inventario[indice].id << "Peso: " << inventario[indice].peso << "Tipo: " << inventario[indice].tipo << std::endl;
			indice++;

		}
		if_stream.close();
		return inventario;
	}
}

bool ItemDaoStream::guardaTodosItens(Item * it_itens) { return true; }
void ItemDaoStream::atualizaItem() {}
void ItemDaoStream::deletaItem() {}
void ItemDaoStream::adicionaItem() {}
