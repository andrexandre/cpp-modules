#include "PhoneBook.hpp"

void	PhoneBook::ADD()
{
	std::string	str;
	if (index == 8)
		index = 0;
	std::cout << "Enter name: ";
	std::getline(std::cin, str);
	if (std::cin.eof() || str.empty())
		return;
	c[index].set_name(0, str);
	std::cout << "Enter lname: ";
	std::getline(std::cin, str);
	if (std::cin.eof() || str.empty())
		return;
	c[index].set_name(1, str);
	std::cout << "Enter nname: ";
	std::getline(std::cin, str);
	if (std::cin.eof() || str.empty())
		return;
	c[index].set_name(2, str);
	std::cout << "Enter ph nr: ";
	std::getline(std::cin, str);
	if (std::cin.eof() || str.empty())
		return;
	c[index].set_name(3, str);
	std::cout << "Enter dk sc: ";
	std::getline(std::cin, str);
	if (std::cin.eof() || str.empty())
		return;
	c[index].set_name(4, str);
	index++;
}

void PhoneBook::PrintField(std::string str)
{
	std::cout << "|";
	if (str.length() > 10)
	{
		std::cout << std::setw(9);
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
}

void PhoneBook::Display()
{
	std::cout << std::right;
	PrintField("Index");
	PrintField("First Name");
	PrintField("Last Name");
	PrintField("Nickname");
	std::cout << "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (c[i].get_name(0).empty())
			break;
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i + 1;
		PrintField(c[i].get_name(0));
		PrintField(c[i].get_name(1));
		PrintField(c[i].get_name(2));
		std::cout << "|" << std::endl;
	}
}

void	PhoneBook::SEARCH()
{
	Display();
	std::string	str;
	int i;
	std::cout << "Enter index: ";
	std::getline(std::cin, str);
	if (str.empty() || str[1] || std::cin.eof())
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	i = str[0] - '0';
	if (i < 0 || i > 7)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (c[i].get_name(0).empty())
	{
		std::cout << "Empty contact" << std::endl;
		return;
	}
	std::cout << i << " = " << c[i].get_name(0).empty() << std::endl;
}

PhoneBook::PhoneBook()
{
	index = 0;
}

int	main(void)
{
	PhoneBook	afb;
	std::string	cmd;
	std::cout << "Welcome to MyAwesomePhoneBook" << std::endl;
	std::cout << "Please enter your command" << std::endl;
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (cmd.empty())
			continue;
		if (cmd == "ADD" || cmd == "a")
			afb.ADD();
		else if (cmd == "SEARCH" || cmd == "s")
			afb.SEARCH();
		else if (cmd == "EXIT" || std::cin.eof())
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
