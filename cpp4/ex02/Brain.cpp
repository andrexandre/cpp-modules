#include "Brain.hpp"

Brain::Brain()
{
	co << MAGENTA;
	co << "Brain Default constructor called" << nl;
	co << RESET;
}

Brain::Brain(const Brain &src)
{
	co << MAGENTA;
	co << "Brain Copy constructor called" << nl;
	co << RESET;
	*this = src;
}

Brain::~Brain()
{
	co << MAGENTA;
	co << "Brain Destructor called" << nl;
	co << RESET;
}

Brain &Brain::operator=(Brain const &rhs)
{
	co << MAGENTA;
	co << "Brain Copy assignment operator called" << nl;
	co << RESET;
	if (this != &rhs)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	return *this;
}

str* Brain::getIdeas()
{
	return(ideas);
}

void Brain::setIdea(str idea, int index)
{
	this->ideas[index] = idea;
}

void Brain::printIdea(int index)
{
	co << ideas[index] << nl;
}
