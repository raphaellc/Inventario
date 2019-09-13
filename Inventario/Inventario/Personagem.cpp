#include "Personagem.h"



Personagem::Personagem()
{
	vida = 50;
}


Personagem::~Personagem()
{
}

void Personagem::recuperarVida()
{
	this->vida = this->vida + this->inventario.pegarItem(POCAO).usar();
}
