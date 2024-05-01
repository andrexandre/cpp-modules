#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Form form("VIP form", 155, 5);
	}
	catch (std::exception &e)
	{
		co << e.what() << nl;
	}
	try
	{
		Bureaucrat vip("President", 3);
		Form form("VIP form", 10, 5);
		co << form;
		vip.signForm(form);
		co << form;
	}
	catch (std::exception &e)
	{
		co << e.what() << nl;
	}
	return (0);
}
