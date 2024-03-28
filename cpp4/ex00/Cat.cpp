#include "Cat.hpp"

Cat::Cat()
{
	co << GREEN;
	co << "Cat Default constructor called" << nl;
	co << RESET;
	type = "Cat";
}

Cat::Cat(const Cat &src)
{
	co << GREEN;
	co << "Cat Copy constructor called" << nl;
	co << RESET;
	*this = src;
}

Cat::~Cat()
{
	co << GREEN;
	co << "Cat Destructor called" << nl;
	co << RESET;
}

Cat &Cat::operator=(Cat const &rhs)
{
	co << GREEN;
	co << "Cat Copy assignment operator called" << nl;
	co << RESET;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void Cat::makeSound() const
{
	co << GREEN;
	co << "Meow Meow" << nl;
	co << RESET;
}
