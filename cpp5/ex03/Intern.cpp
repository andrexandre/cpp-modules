#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

AForm *Intern::makeForm(const str &formName, const str &formTarget)
{
	AForm *form = NULL;
	str forms_str[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
		"PresidentialPardonForm"
	};
	int i = 0;
	while (i < 4 && forms_str[i].compare(formName))
		i++ ;
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(formTarget);
			break;
		case 1:
			form = new RobotomyRequestForm(formTarget);
			break;
		case 2:
			form = new PresidentialPardonForm(formTarget);
			break;
		default:
			co << RED"Error: No form found"END << nl;
	}
	if (form)
		co << WHITE"Intern creates " << forms_str[i] << END << nl;
	return form;
}
