#include "Personagem.h"
#include "Item.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
	int ids_itens = 0;
	Personagem * prs = new Personagem;
	Item * i = new Item;
	Item i2;
	enum Tipo { ARMA, VESTIMENTA, POCAO, ARTEFATO };
	ofstream gravaItem("Inventario.bin", ios::binary | ios::out);
	ifstream leItem;
	//Cria o Item
	i->id = ids_itens++; //grava e atualiza item;
	i->tipo = ARMA;
	i->peso = 10;
	//Atribui ao Personagem
	prs->item_atual = *i;
	
	
	//Grava o Item
	// - Testa se stream abriu Arquivo
	if (!gravaItem.is_open()) {
		cerr << "Erro ao abrir o arquivo" << endl;
		exit(1);
	}
	prs->inserirItem(gravaItem);
	gravaItem.close();
	leItem.open("Inventario.bin", ios::binary | ios::in);
	if (!leItem.is_open()) {
		cerr << "Erro ao abrir o arquivo" << endl;
		exit(1);
	}
	leItem.read((char *)&i2, sizeof(Item));
	cout << "Id: " << i2.id << "Peso: " << i2.peso << "Tipo: " << i2.tipo << endl;

	system("pause");
	return 0;
}
