#include "Contact.hpp"

std::string Contact::get_name(int i)
{
	if (i == 0)
		return (name);
	else if (i == 1)
		return (last_name);
	else if (i == 2)
		return (nickname);
	else if (i == 3)
		return (phone_number);
	else if (i == 4)
		return (darkest_secret);
	std::cerr << "Invalid index" << std::endl;
	return (NULL);
}

void Contact::set_name(int i, std::string str)
{
	if (i == 0)
		name = str;
	else if (i == 1)
		last_name = str;
	else if (i == 2)
		nickname = str;
	else if (i == 3)
		phone_number = str;
	else if (i == 4)
		darkest_secret = str;
	else
		std::cerr << "Invalid index" << std::endl;
}
