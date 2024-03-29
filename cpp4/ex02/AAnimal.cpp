#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	co << "AAnimal Default constructor called" << nl;
	type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &src)
{
	co << "AAnimal Copy constructor called" << nl;
	*this = src;
}

AAnimal::~AAnimal()
{
	co << "AAnimal Destructor called" << nl;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	co << "AAnimal Copy assignment operator called" << nl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

str AAnimal::getType() const
{
	return this->type;
}

void AAnimal::setType(str type)
{
	this->type = type;
}
