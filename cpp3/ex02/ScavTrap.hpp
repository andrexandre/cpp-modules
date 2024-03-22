#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(ScavTrap const &src);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap const &rhs);

		ScavTrap(str name);
		void attack(const std::string& target);
		void guardGate();
};

#endif