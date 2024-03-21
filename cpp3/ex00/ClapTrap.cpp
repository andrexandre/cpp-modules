#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDmg(0)
{
	co << "ClapTrap " << _name << " constructor called" << nl;
}

ClapTrap::ClapTrap(str name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDmg(0)
{
	co << "ClapTrap " << _name << " constructor called" << nl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	co << "ClapTrap copy constructor called" << nl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	co << "ClapTrap " << _name << " destructor called" << nl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	co << "ClapTrap copy assignment operator called" << nl;
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
	if (_hitPoints <= 0)
	{
		co << "ClapTrap " << _name << " is already dead" << nl;
		return;
	}
	if (_energyPoints <= 0)
	{
		co << "ClapTrap " << _name << " can't attack because it's out of energy" << nl;
		return;
	}
	_energyPoints--;
	co << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDmg << " points of damage!" << nl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		co << "ClapTrap " << _name << " is already dead" << nl;
		return;
	}
	_hitPoints -= amount;
	co << "ClapTrap " << _name << " took " << amount << " points of damage" << nl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		co << "ClapTrap " << _name << " is dead" << nl;
		return;
	}
	if (_energyPoints <= 0)
	{
		co << "ClapTrap " << _name << " can't be repaired because it's out of energy" << nl;
		return;
	}
	_hitPoints += amount;
	_energyPoints--;
	co << "ClapTrap " << _name << " repaired " << amount << " hit points" << nl;
}
