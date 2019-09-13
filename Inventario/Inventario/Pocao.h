#pragma once
#include "Item.h"
class Pocao :
	public Item
{
public:
	Pocao();
	~Pocao();
	int usar() override;
};

