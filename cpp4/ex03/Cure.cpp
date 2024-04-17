#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &src) : AMateria(src)
{
	*this = src;
}

Cure::~Cure()
{
}

Cure &Cure::operator=(Cure const &rhs)
{
	if (this != &rhs)
		(void)rhs;
	return *this;
}

Cure *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	co << "* heals " << target.getName() << "'s wounds *" << nl;
}
