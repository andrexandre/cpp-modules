#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &src) : AMateria(src)
{
	*this = src;
}

Ice::~Ice()
{
}

Ice &Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
		(void)rhs;
	return *this;
}

Ice *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	co << "* shoots an ice bolt at " << target.getName() << " *" << nl;
}
