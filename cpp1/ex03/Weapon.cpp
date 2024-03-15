#include "Weapon.hpp"

Weapon::Weapon(string weaponType)
{
	this->setType(weaponType);
}

string const &Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(string weaponType)
{
	this->type = weaponType;
}
