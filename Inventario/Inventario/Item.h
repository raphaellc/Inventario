#pragma once
#include <iostream>
enum TIPO_ITEM { POCAO, ESCUDO, ESPADA };
class Item
{
public:
	Item();
	~Item();
	int id, peso;
	TIPO_ITEM tipo;
	virtual int usar();
	void definirTipo(TIPO_ITEM tp);

};

