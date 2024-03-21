#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default")
{
	co << "ScavTrap " << _name << " constructor called" << nl;
}

ScavTrap::ScavTrap(str name) : ClapTrap(name)
{
	co << "ScavTrap " << _name << " constructor called" << nl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	co << "ScavTrap copy constructor called" << nl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	co << "ScavTrap " << _name << " destructor called" << nl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	co << "ScavTrap copy assignment operator called" << nl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDmg = rhs._attackDmg;
	}
	return *this;
}
