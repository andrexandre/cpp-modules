#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string

class FragTrap
{
	public:
		FragTrap();
		FragTrap(FragTrap const &src);
		~FragTrap();
		FragTrap &operator=(FragTrap const &rhs);

		FragTrap(str name);

	private:
		
};

#endif