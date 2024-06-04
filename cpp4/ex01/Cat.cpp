#include "Cat.hpp"

Cat::Cat() : Animal()
{
	co << GREEN;
	co << "Cat Default constructor called" << nl;
	co << RESET;
	brain = new Brain();
	type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src)
{
	co << GREEN;
	co << "Cat Copy constructor called" << nl;
	co << RESET;
	brain = new Brain(*src.brain);
	*this = src;
}

Cat::~Cat()
{
	delete brain;
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
	{
		this->type = rhs.type;
		*this->brain = *rhs.brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	co << GREEN;
	co << "Meow Meow" << nl;
	co << RESET;
}
