#include "Item.h"
using namespace std;


Item::Item()
{
}


Item::~Item()
{
}

int Item::usar()
{
	return 0;
}

void Item::definirTipo(TIPO_ITEM tp)
{
	tipo = tp;
}
//a == b
//a.operator==(b)
bool Item::operator==(Item * it)
{
	if (this->id == it->id && this->tipo == it->tipo && this->peso == it->peso) {
		return true;
	}else
		return false;
}
bool Item::operator>(Item * it)
{
	return this->peso > it->peso;
}

std::ostream & operator<<(std::ostream & os, const Item * obj)
{
	os << obj->id;
	return os;
}
