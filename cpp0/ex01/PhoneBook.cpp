#include "PhoneBook.hpp"

void replaceChar(std::string& str, char toSearch, char toReplace)
{
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == toSearch)
			str[i] = toReplace;
}

void PhoneBook::ADD()
{
	std::string str;
	if (index == 8)
		index = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cout << GREEN;
		if (i == 0)
			std::cout << "Enter name: ";
		else if (i == 1)
			std::cout << "Enter last name: ";
		else if (i == 2)
			std::cout << "Enter nickname: ";
		else if (i == 3)
			std::cout << "Enter phone num: ";
		else if (i == 4)
			std::cout << "Enter secret: ";
		std::cout << RESET;
		std::getline(std::cin, str);
		if (str.find_first_not_of(" \t") == std::string::npos)
			return (c[index].clear());
		if (str.find_first_of('\t') != std::string::npos)
			replaceChar(str, '\t', ' ');
		if (std::cin.eof() || str.empty())
			return (c[index].clear());
		c[index].set_name(i, str);
	}
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
	std::cout << std::right << CYAN;
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
	std::cout << RESET;
}

void PhoneBook::SEARCH()
{
	if (c[0].get_name(0).empty())
	{
		std::cout << BLUE "Empty phonebook" RESET << std::endl;
		return;
	}
	Display();
	std::string	str;
	int i;
	std::cout << GREEN "Enter index: " RESET;
	std::getline(std::cin, str);
	if (str.empty() || str[1] || std::cin.eof())
	{
		std::cout << RED "Invalid index" RESET << std::endl;
		return;
	}
	i = str[0] - '0';
	if (i < 1 || i > 8)
	{
		std::cout << RED "Invalid index" RESET << std::endl;
		return;
	}
	i--;
	if (c[i].get_name(0).empty())
	{
		std::cout << BLUE "Empty contact" RESET << std::endl;
		return;
	}
	std::cout << std::endl << BLUE;
	std::cout << "First Name: " << c[i].get_name(0) << std::endl;
	std::cout << " Last Name: " << c[i].get_name(1) << std::endl;
	std::cout << "  Nickname: " << c[i].get_name(2) << std::endl;
	std::cout << " Phone Num: " << c[i].get_name(3) << std::endl;
	std::cout << "    Secret: " << c[i].get_name(4) << std::endl;
	std::cout << RESET;
}

PhoneBook::PhoneBook()
{
	index = 0;
}

int main(void)
{
	PhoneBook	mafb;
	std::string	cmd;
	std::cout << WHITE "Welcome to MyAwesomePhoneBook" << std::endl;
	std::cout << "Please enter your command" << std::endl;
	std::cout << "Commands: " GREEN "ADD" RESET ", " BLUE "SEARCH";
	std::cout << RESET ", " RED "EXIT" RESET << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (cmd.empty())
			continue;
		if (cmd == "ADD")
			mafb.ADD();
		else if (cmd == "SEARCH")
			mafb.SEARCH();
		else if (cmd == "EXIT" || std::cin.eof())
			break;
		else
			std::cout << RED "Invalid command" RESET << std::endl;
	}
	if (std::cin.eof())
		std::cout << std::endl;
	return 0;
}
