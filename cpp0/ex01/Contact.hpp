#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip> // std::setw
#include <iostream> // std::cout
#include <string> // std::string

class	Contact
{
public:
	std::string	get_name(int i);
	void		set_name(int i, std::string str);
	void		clear();
private:
	std::string	name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif
