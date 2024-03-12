#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#include <iomanip> // std::setw
#include <iostream> // std::cout
#include <string> // std::string
#include "Contact.hpp"

class	PhoneBook {
public:
	PhoneBook();
	void	ADD();
	void	SEARCH();
private:
	void	Display();
	void	PrintField(std::string str);
	Contact	c[8];
	int		index;
};

#endif
