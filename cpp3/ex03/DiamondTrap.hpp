#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		using FragTrap::_hitPoints;
		using ScavTrap::_energyPoints;
		using FragTrap::_attackDmg;
		using ScavTrap::attack;

		DiamondTrap();
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap();
		DiamondTrap &operator=(DiamondTrap const &rhs);

		DiamondTrap(str name);
		void whoAmI();

	private:
		str _name;
};

#endif