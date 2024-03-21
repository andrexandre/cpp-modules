#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct("C. Guy");
	ct.attack("them");
	ct.takeDamage(5);
	ct.beRepaired(5);
	return 0;
}
