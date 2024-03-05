#include <iostream>

class	Contact {
public:
	std::string	name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

class	PhoneBook {
public:
	Contact	c[8];
	int		index;
};

int	main(void)
{
	// PhoneBook	fnbk;
	std::string	cmd;
	std::cout << "Welcome to MyAwesomePhoneBook" << std::endl;
	std::cout << "Please enter your command" << std::endl;
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "> ";
		std::cin >> cmd;
		if (cmd == "ADD")
			std::cout << cmd << std::endl;
		else if (cmd == "SEARCH")
			std::cout << cmd << std::endl;
		else if (cmd == "EXIT" || std::cin.eof())
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
		// 	std::cout << fnbk.c[0] << std::endl;
	std::cout << std::endl;
	return 0;
}
