#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	co << GREEN;
	co << "Cat Default constructor called" << nl;
	co << RESET;
	brain = new Brain();
	type = "Cat";
}

Cat::Cat(const Cat &src) : AAnimal(src)
{
	co << GREEN;
	co << "Cat Copy constructor called" << nl;
	co << RESET;
	brain = new Brain();
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

void Cat::setIdea(str idea, int index)
{
	this->brain->setIdea(idea, index);
}

void Cat::printIdea(int index)
{
	this->brain->printIdea(index);
}

void Cat::printMemory() const
{
	co << "Brain's memory: " << this->brain << nl;
}
