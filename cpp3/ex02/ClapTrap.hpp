#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(ClapTrap const &src);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &rhs);

		ClapTrap(str name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		str _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDmg;
};

#endif
