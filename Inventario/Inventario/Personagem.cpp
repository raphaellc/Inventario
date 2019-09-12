#include "Personagem.h"



Personagem::Personagem()
{
	quantidade = 0;
}


Personagem::~Personagem()
{
}

void Personagem::inserirItem(std::ostream & os)
{
	os.write((char*)&item_atual, sizeof(Item));
	quantidade++;
}

void Personagem::inserirItemEm(std::ostream & os, int indice)
{
	std::streampos pos(indice * sizeof(Item));
	os.seekp(pos);
	std::cout << "O item ser� escrito na posi��o: " << os.tellp() << std::endl;
	os.write((char*)&item_atual, sizeof(Item));
	quantidade++;
}

void Personagem::carregaItens(std::istream & is)
{
	int indice = 0;
	while(!is.eof()){
		
		is.read(reinterpret_cast<char *>(&inventario[indice]), sizeof(Item));
		/*if (is.gcount() == 0) break;
		std::cout << "Id: " << inventario[indice].id << "Peso: " << inventario[indice].peso << "Tipo: " << inventario[indice].tipo << std::endl;
		indice++;*/
		
	}
}

int Personagem::obtemQuantidadeItens()
{
	return quantidade;
}

