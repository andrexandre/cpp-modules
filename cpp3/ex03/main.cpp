#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dt("D. Guy");
	// dt.attack("them");
	// dt.takeDamage(5);
	// dt.beRepaired(5);
	// dt.guardGate();
	// dt.highFivesGuys();
	dt.whoAmI();
	return 0;
}
/*
FragTrap::_hitPoints; 100
ScavTrap::_energyPoints; 50
FragTrap::_attackDmg; 30
ScavTrap::attack;
*/