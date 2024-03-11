#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip> // std::setw
#include <iostream> // std::cout
#include <string> // std::string
#include "Contact.hpp"

class	PhoneBook {
public:
	PhoneBook();
	void	ADD();
	void	SEARCH();
	void	Display();
	void	PrintField(std::string str);
private:
	Contact	c[8];
	int		index;
};

#endif
