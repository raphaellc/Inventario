#include "Personagem.h"



Personagem::Personagem()
{
}


Personagem::~Personagem()
{
}

void Personagem::inserirItem(std::ostream & os)
{
	os.write((char*)&item_atual, sizeof(Item));
}

void Personagem::inserirItemEm(std::ostream & os, int indice)
{
	std::streampos pos(indice * sizeof(Item));
	os.seekp(pos);
	std::cout << "O item será escrito na posição: " << os.tellp() << std::endl;
	os.write((char*)&item_atual, sizeof(Item));
}

void Personagem::carregaItens(std::istream & is)
{
	int indice = 0;
	while(!is.eof()){
		
		is.read((char *)&inventario[indice], sizeof(Item));
		if (is.gcount() == 0) break;
		std::cout << "Id: " << inventario[indice].id << "Peso: " << inventario[indice].peso << "Tipo: " << inventario[indice].tipo << std::endl;
		indice++;
		
	}
}

