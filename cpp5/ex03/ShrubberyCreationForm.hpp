#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <fstream> // std::ifstream

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const str &name);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

		void beExecuted() const;
};

#endif
