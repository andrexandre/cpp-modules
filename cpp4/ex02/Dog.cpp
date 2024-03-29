#include "Dog.hpp"

Dog::Dog()
{
	co << BLUE;
	co << "Dog Default constructor called" << nl;
	co << RESET;
	brain = new Brain();
	type = "Dog";
}

Dog::Dog(const Dog &src)
{
	co << BLUE;
	co << "Dog Copy constructor called" << nl;
	co << RESET;
	brain = new Brain();
	*this = src;
}

Dog::~Dog()
{
	delete brain;
	co << BLUE;
	co << "Dog Destructor called" << nl;
	co << RESET;
}

Dog &Dog::operator=(Dog const &rhs)
{
	co << BLUE;
	co << "Dog Copy assignment operator called" << nl;
	co << RESET;
	if (this != &rhs)
	{
		this->type = rhs.type;
		*this->brain = *rhs.brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	co << BLUE;
	co << "Roof Roof" << nl;
	co << RESET;
}
