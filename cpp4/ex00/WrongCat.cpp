#include "WrongCat.hpp"

WrongCat::WrongCat()
//  : WrongAnimal()
{
	co << YELLOW;
	co << "WrongCat Default constructor called" << nl;
	co << RESET;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src)
//  : WrongAnimal(src)
{
	co << YELLOW;
	co << "WrongCat Copy constructor called" << nl;
	co << RESET;
	*this = src;
}

WrongCat::~WrongCat()
{
	co << YELLOW;
	co << "WrongCat Destructor called" << nl;
	co << RESET;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	co << YELLOW;
	co << "WrongCat Copy assignment operator called" << nl;
	co << RESET;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void WrongCat::makeSound() const
{
	co << YELLOW;
	co << "Mrrrowl Hiss" << nl;
	co << RESET;
}
