#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDmg = 30;
	co << YELLOW;
	co << "FragTrap " << _name << " constructor called" << nl;
	co << RESET;
}

FragTrap::FragTrap(str name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDmg = 30;
	co << YELLOW;
	co << "FragTrap " << _name << " constructor called" << nl;
	co << RESET;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	co << YELLOW;
	co << "FragTrap copy constructor called" << nl;
	co << RESET;
	*this = src;
}

FragTrap::~FragTrap()
{
	co << YELLOW;
	co << "FragTrap " << _name << " destructor called" << nl;
	co << RESET;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	co << YELLOW;
	co << "FragTrap copy assignment operator called" << nl;
	co << RESET;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDmg = rhs._attackDmg;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	co << YELLOW;
	co << "FragTrap " << _name << " requests a high five" << nl;
	co << RESET;
}
