#include "Animal.hpp"

Animal::Animal()
{
	co << "Animal Default constructor called" << nl;
	type = "Animal";
}

Animal::Animal(const Animal &src)
{
	co << "Animal Copy constructor called" << nl;
	*this = src;
}

Animal::~Animal()
{
	co << "Animal Destructor called" << nl;
}

Animal &Animal::operator=(Animal const &rhs)
{
	co << "Animal Copy assignment operator called" << nl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

str Animal::getType() const
{
	return this->type;
}

void Animal::setType(str type)
{
	this->type = type;
}

void Animal::makeSound() const
{
	co << "*an animal sound is heard in the atmosphere*" << nl;
}
