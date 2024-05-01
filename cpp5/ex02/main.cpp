#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		ShrubberyCreationForm shrubForm("shrub");
		RobotomyRequestForm robotForm("robot");
		PresidentialPardonForm pardonForm("pardon");
		Bureaucrat vip("President", 3);
		co << shrubForm;
		co << robotForm;
		co << pardonForm;
		vip.signForm(pardonForm);
		co << pardonForm;
		vip.executeForm(pardonForm);
	}
	catch (std::exception &e)
	{
		co << e.what() << nl;
	}
	try
	{
		PresidentialPardonForm pardonForm("pardon");
		Bureaucrat vip("President", 3);
		co << pardonForm;
		// vip.signForm(pardonForm);
		// co << pardonForm;
		vip.executeForm(pardonForm);
	}
	catch (std::exception &e)
	{
		co << e.what() << nl;
	}
	return (0);
}
