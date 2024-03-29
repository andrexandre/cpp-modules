#include "Character.hpp"

Character::Character()
{
}

Character::Character(const Character &src)
{
	*this = src;
}

Character::~Character()
{
}

Character &Character::operator=(Character const &rhs)
{
	if (this != &rhs)
		(void)rhs;
	return *this;
}

