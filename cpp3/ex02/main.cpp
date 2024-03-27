#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap ft("F. Guy");
	ft.attack("them");
	ft.takeDamage(5);
	ft.beRepaired(5);
	ft.highFivesGuys();
	return 0;
}
