#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	rrf->beExecuted();
	delete rrf;
	return (0);
}
