#include "Weapon.hpp"

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
	this->type = type;
}
