#include "PhoneBook.hpp"

void ReplaceChar(string& str, char toSearch, char toReplace)
{
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == toSearch)
			str[i] = toReplace;
}

void PhoneBook::ADD()
{
	string str;
	if (index == MAX_CONTACTS)
		index = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << GREEN;
		if (i == 0)
			cout << "Enter first name: ";
		else if (i == 1)
			cout << "Enter last name: ";
		else if (i == 2)
			cout << "Enter nickname: ";
		else if (i == 3)
			cout << "Enter phone num: ";
		else if (i == 4)
			cout << "Enter secret: ";
		cout << RESET;
		std::getline(cin, str);
		if (cin.eof())
			return;
		if (str.empty() || str.find_first_not_of(" \t") == string::npos)
		{
			cout << RED "Invalid input" RESET << endl;
			i--;
			continue;
		}
		if (str.find_first_of('\t') != string::npos)
			ReplaceChar(str, '\t', ' ');
		c[index].set_name(i, str);
	}
	index++;
}

void PrintField(string str)
{
	cout << "|";
	if (str.length() > 10)
	{
		cout << std::setw(9);
		cout << str.substr(0, 9) << ".";
	}
	else
	{
		cout << std::setw(10);
		cout << str;
	}
}

void PhoneBook::DisplayTable()
{
	cout << std::right << CYAN;
	PrintField("Index");
	PrintField("First Name");
	PrintField("Last Name");
	PrintField("Nickname");
	cout << "|" << endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (c[i].get_name(0).empty())
			break;
		cout << "|";
		cout << std::setw(10);
		cout << i + 1;
		PrintField(c[i].get_name(0));
		PrintField(c[i].get_name(1));
		PrintField(c[i].get_name(2));
		cout << "|" << endl;
	}
	cout << RESET;
}

void PhoneBook::SEARCH()
{
	if (c[0].get_name(0).empty())
	{
		cout << BLUE "Empty phonebook" RESET << endl;
		return;
	}
	DisplayTable();
	string	str;
	cout << GREEN "Enter index: " RESET;
	std::getline(cin, str);
	if (str.empty() || str[1] || cin.eof())
	{
		cout << RED "Invalid index" RESET << endl;
		return;
	}
	int i = str[0] - '0';
	if (i < 1 || i > MAX_CONTACTS)
	{
		cout << RED "Invalid index" RESET << endl;
		return;
	}
	i--;
	if (c[i].get_name(0).empty())
	{
		cout << BLUE "Empty contact" RESET << endl;
		return;
	}
	cout << endl << BLUE;
	cout << "First Name: " << c[i].get_name(0) << endl;
	cout << " Last Name: " << c[i].get_name(1) << endl;
	cout << "  Nickname: " << c[i].get_name(2) << endl;
	cout << " Phone Num: " << c[i].get_name(3) << endl;
	cout << "    Secret: " << c[i].get_name(4) << endl;
	cout << RESET;
}

PhoneBook::PhoneBook()
{
	index = 0;
}

int main(void)
{
	PhoneBook	mafb;
	string	cmd;
	cout << WHITE "Welcome to MyAwesomePhoneBook" << endl;
	cout << "Please enter your command" << endl;
	cout << "Commands: " GREEN "ADD" RESET ", " BLUE "SEARCH";
	cout << RESET ", " RED "EXIT" RESET << endl;
	while (!cin.eof())
	{
		cout << "> ";
		std::getline(cin, cmd);
		if (cmd.empty())
			continue;
		if (cmd == "ADD")
			mafb.ADD();
		else if (cmd == "SEARCH")
			mafb.SEARCH();
		else if (cmd == "EXIT" || cin.eof())
			break;
		else
			cout << RED "Invalid command" RESET << endl;
	}
	if (cin.eof())
		cout << endl;
	return 0;
}
