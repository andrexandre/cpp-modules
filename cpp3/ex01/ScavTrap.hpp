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
		ScavTrap(str name);
		ScavTrap(ScavTrap const &src);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap const &rhs);

	private:
};
#endif