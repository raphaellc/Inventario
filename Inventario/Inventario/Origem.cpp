#include "Personagem.h"
#include <fstream>
#include <string>

using namespace std;
int main() {
	int ids_itens = 0;
	Personagem * prs = new Personagem;
	//Inicializa Jogo
	
	/*** Cria Itens ***/
	Item * i = new Item;
	Item * i2 = new Item;
	Item * i3 = new Item;
		
	//Cria o Item
	i->id = ids_itens++; //grava e atualiza item;
	i->tipo = POCAO;
	i->peso = 10;
	
	//Cria o Item
	i2->id = ids_itens++; //grava e atualiza item;
	i2->tipo = ESCUDO;
	i2->peso = 20;
	prs->coletaItem(i2);
	
	//Cria o Item
	i3->id = ids_itens++; //grava e atualiza item;
	i3->tipo = ESPADA;
	i3->peso = 30;
	prs->coletaItem(i3);
	prs->guardaItens();

	// Salva Jogo
	//Reinicializa Jogo com recursos salvos no arquivo.
	
	system("pause");
	return 0;
}
