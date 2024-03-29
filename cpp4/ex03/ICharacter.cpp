#include "ICharacter.hpp"

ICharacter::ICharacter()
{
}

ICharacter::ICharacter(const ICharacter &src)
{
	*this = src;
}

ICharacter &ICharacter::operator=(ICharacter const &rhs)
{
	if (this != &rhs)
		(void)rhs;
	return *this;
}

