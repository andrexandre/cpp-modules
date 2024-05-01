#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const str &name) : AForm(name, 145, 137)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	(void)rhs;
	return *this;
}

void PresidentialPardonForm::beExecuted() const
{
	co << YELLOW << this->getName() << " has been pardoned by Zaphod Beeblebrox!\n"END;
}
