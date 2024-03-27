#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), 
ScavTrap("default"), FragTrap("default")
{
	_name = "default";
	this->ClapTrap::_name = "default_clap_name";
	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDmg = 30;
	co << RED;
	co << "DiamondTrap " << _name << " constructor called" << nl;
	co << RESET;
}

DiamondTrap::DiamondTrap(str name) : ClapTrap(name + str("_clap_name")), 
ScavTrap(name), FragTrap(name)
{
	_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	FragTrap::_hitPoints = 100;
	ScavTrap::_energyPoints = 50;
	FragTrap::_attackDmg = 30;
	co << RED;
	co << "DiamondTrap " << _name << " constructor called" << nl;
	co << RESET;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	co << RED;
	co << "DiamondTrap copy constructor called" << nl;
	co << RESET;
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	co << RED;
	co << "DiamondTrap " << _name << " destructor called" << nl;
	co << RESET;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	co << RED;
	co << "DiamondTrap copy assignment operator called" << nl;
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

void DiamondTrap::whoAmI()
{
	co << RED;
	co << "My DiamondTrap's name is " << this->_name << nl;
	co << "My ClapTrap's name is    " << this->ClapTrap::_name << nl;
	co << RESET;
}
