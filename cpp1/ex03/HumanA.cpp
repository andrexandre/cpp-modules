#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
}

void HumanA::attack()
{
	cout << name << " attacks with their " << weapon.getType() << endl;
}
