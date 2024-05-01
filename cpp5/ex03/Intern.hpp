#ifndef INTERN_HPP
#define INTERN_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(Intern const &src);
		~Intern();
		Intern &operator=(Intern const &rhs);

		AForm *makeForm(const str &formName, const str &formTarget);
};

#endif
