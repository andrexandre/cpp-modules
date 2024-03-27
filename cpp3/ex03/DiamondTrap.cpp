#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default" + str("_clap_trap")), 
ScavTrap("default" + str("_scav_trap")), FragTrap("default" + str("_frag_trap"))
{
	_name = "default";
	co << RED;
	co << "DiamondTrap " << _name << " constructor called" << nl;
	co << RESET;
}

DiamondTrap::DiamondTrap(str name) : ClapTrap(name + str("_clap_trap")), 
ScavTrap(name + str("_scav_trap")), FragTrap(name + str("_frag_trap"))
{
	_name = name;
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
