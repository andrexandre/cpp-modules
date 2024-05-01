#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const str &name) : AForm(name, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	(void)rhs;
	return *this;
}

void RobotomyRequestForm::beExecuted() const
{
	co << BLUE << "*drilling noises*\n";
	srand(time(NULL));
	if (rand() % 2)
		co << this->getName() << " has robotomized successfully!\n";
	else
		co << "Robotomy failed.\n";
	co << END;
}
