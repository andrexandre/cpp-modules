#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(str name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &rhs);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		str _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDmg;
};

#endif
