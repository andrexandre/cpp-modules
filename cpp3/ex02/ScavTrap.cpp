#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDmg = 20;
	co << GREEN;
	co << "ScavTrap " << _name << " constructor called" << nl;
	co << RESET;
}

ScavTrap::ScavTrap(str name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDmg = 20;
	co << GREEN;
	co << "ScavTrap " << _name << " constructor called" << nl;
	co << RESET;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDmg = 20;
	co << GREEN;
	co << "ScavTrap copy constructor called" << nl;
	co << RESET;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	co << GREEN;
	co << "ScavTrap " << _name << " destructor called" << nl;
	co << RESET;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	co << GREEN;
	co << "ScavTrap copy assignment operator called" << nl;
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

void ScavTrap::attack(const std::string& target)
{
	co << GREEN;
	if (_hitPoints <= 0)
	{
		co << "ScavTrap " << _name << " is already dead" << nl;
		co << RESET;
		return;
	}
	if (_energyPoints <= 0)
	{
		co << "ScavTrap " << _name << " can't attack because it's out of energy" << nl;
		co << RESET;
		return;
	}
	_energyPoints--;
	co << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << nl;
	co << RESET;
}

void ScavTrap::guardGate()
{
	co << GREEN;
	co << "ScavTrap is now in Gate keeper mode" << nl;
	co << RESET;
}
