#include "Personagem.h"



Personagem::Personagem()
{
	vida = 50;
	this->inventario = new Inventario(1);
}


Personagem::~Personagem()
{
}

void Personagem::recuperarVida()
{
	this->vida = this->vida + this->inventario->pegarItem(POCAO)->usar();
}

void Personagem::coletaItem(Item * it)
{
	inventario->adicionaItem(it);
}

void Personagem::guardaItens()
{
	this->inventario->salvaInventario();
}
