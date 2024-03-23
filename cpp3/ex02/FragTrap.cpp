#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDmg = 30;
	co << YELLOW;
	co << "ScavTrap " << _name << " constructor called" << nl;
	co << RESET;
}

FragTrap::FragTrap(str name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDmg = 30;
	co << YELLOW;
	co << "ScavTrap " << _name << " constructor called" << nl;
	co << RESET;
}

FragTrap::~FragTrap()
{
	co << YELLOW;
	co << "ScavTrap " << _name << " destructor called" << nl;
	co << RESET;
}

FragTrap::FragTrap(FragTrap const &src)
{
	co << "ScavTrap " << _name << " destructor called" << nl;
	*this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDmg = rhs._attackDmg;
	}
	return *this;
}
