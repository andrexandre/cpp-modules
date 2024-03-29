#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	co << RED;
	co << "WrongAnimal Default constructor called" << nl;
	co << RESET;
	co << RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	co << RED;
	co << "WrongAnimal Copy constructor called" << nl;
	co << RESET;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	co << RED;
	co << "WrongAnimal Destructor called" << nl;
	co << RESET;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	co << RED;
	co << "WrongAnimal Copy assignment operator called" << nl;
	co << RESET;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

str WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::setType(str type)
{
	this->type = type;
}

void WrongAnimal::makeSound() const
{
	co << RED;
	co << "*an unusual sound is heard in the atmosphere*" << nl;
	co << RESET;
}
