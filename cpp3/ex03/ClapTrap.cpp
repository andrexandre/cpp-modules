#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDmg(0)
{
	co << BLUE;
	co << "ClapTrap " << _name << " constructor called" << nl;
	co << RESET;
}

ClapTrap::ClapTrap(str name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDmg(0)
{
	co << BLUE;
	co << "ClapTrap " << _name << " constructor called" << nl;
	co << RESET;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	co << BLUE;
	co << "ClapTrap copy constructor called" << nl;
	co << RESET;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	co << BLUE;
	co << "ClapTrap " << _name << " destructor called" << nl;
	co << RESET;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	co << BLUE;
	co << "ClapTrap copy assignment operator called" << nl;
	co << RESET;
	if (this != &rhs)
	{
		this->_attackDmg = rhs._attackDmg;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
		this->_name = rhs._name;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	co << BLUE;
	if (_hitPoints <= 0)
	{
		co << "ClapTrap " << _name << " is already dead" << nl;
		co << RESET;
		return;
	}
	if (_energyPoints <= 0)
	{
		co << "ClapTrap " << _name << " can't attack because it's out of energy" << nl;
		co << RESET;
		return;
	}
	_energyPoints--;
	co << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << nl;
	co << RESET;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	co << BLUE;
	if (_hitPoints <= 0)
	{
		co << "ClapTrap " << _name << " is already dead" << nl;
		co << RESET;
		return;
	}
	_hitPoints -= amount;
	co << "ClapTrap " << _name << " took " << amount << " points of damage" << nl;
	co << RESET;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	co << BLUE;
	if (_hitPoints <= 0)
	{
		co << "ClapTrap " << _name << " is dead" << nl;
		co << RESET;
		return;
	}
	if (_energyPoints <= 0)
	{
		co << "ClapTrap " << _name << " can't be repaired because it's out of energy" << nl;
		co << RESET;
		return;
	}
	_hitPoints += amount;
	_energyPoints--;
	co << "ClapTrap " << _name << " repaired " << amount << " hit points" << nl;
	co << RESET;
}
