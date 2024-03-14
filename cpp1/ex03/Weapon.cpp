#include "Weapon.hpp"

Weapon::Weapon(void)
{
}

Weapon::Weapon(string type)
{
	this->type = type;
}

string const &Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(string type)
{
	this->type.clear();
	this->type = type;
}
