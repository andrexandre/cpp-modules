#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
}

void HumanB::attack()
{
	if (weapon)
		cout << name << " attacks with their " << weapon->getType() << endl;
	else
		cout << name << " attacks with their hands" << endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
