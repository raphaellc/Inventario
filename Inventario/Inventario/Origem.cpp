#include "Personagem.h"
#include <fstream>
#include <string>

using namespace std;
int main() {
	int ids_itens = 0;
	Personagem * prs = new Personagem;

	/*
	Item * i = new Item;
	Item * i2 = new Item;
	Item * i3 = new Item;
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
	//Cria o Item
	i2->id = ids_itens++; //grava e atualiza item;
	i2->tipo = VESTIMENTA;
	i2->peso = 20;
	prs->item_atual = *i2;
	prs->inserirItemEm(gravaItem, 1);
	//Cria o Item
	i3->id = ids_itens++; //grava e atualiza item;
	i3->tipo = POCAO;
	i3->peso = 30;
	prs->item_atual = *i3;
	prs->inserirItemEm(gravaItem, 2);
	gravaItem.close();
	leItem.open("Inventario.bin", ios::binary | ios::in);
	if (!leItem.is_open()) {
		cerr << "Erro ao abrir o arquivo" << endl;
		exit(1);
	}
	//cout << leItem.tellg() << endl;
	//streampos pos(0 * sizeof(Item));
	//leItem.seekg(pos);
	/*leItem.read((char *)&i3, sizeof(Item));
	cout << "Id: " << i3.id << "Peso: " << i3.peso << "Tipo: " << i3.tipo << endl;*/
	/*prs->carregaItens(leItem);
	for(int j = 0; j < prs->obtemQuantidadeItens(); j++)
	{
		cout << "Id: " << prs->inventario[j].id << "Peso: " << prs->inventario[j].peso << "Tipo: " << prs->inventario[j].tipo << endl;
	} 
	leItem.close();*/
	system("pause");
	return 0;
}
