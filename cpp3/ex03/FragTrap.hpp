#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(FragTrap const &src);
		~FragTrap();
		FragTrap &operator=(FragTrap const &rhs);

		FragTrap(str name);
		void highFivesGuys(void);
};

#endif