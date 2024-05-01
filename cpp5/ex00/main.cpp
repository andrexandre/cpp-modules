#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat vip("President", 3);
		co << vip;
		vip.incrementGrade();
		vip.incrementGrade();
		co << vip;
		vip.incrementGrade();
		co << vip; // didn't reach
	}
	catch (std::exception &e)
	{
		co << e.what() << nl;
	}
	try
	{
		Bureaucrat vup("plebeian", 150);
		co << vup;
		vup.decrementGrade();
		co << vup; // didn't reach
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
