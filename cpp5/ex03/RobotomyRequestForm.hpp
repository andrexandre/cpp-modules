#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <stdlib.h> // srand, rand
#include <time.h>   // time

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const str &name);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

		void beExecuted() const;
};

#endif
