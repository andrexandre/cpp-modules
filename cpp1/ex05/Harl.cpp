#include "Harl.hpp"

// NO IF/ELSE STATEMENTS

void Harl::complain(string level)
{
	string complain_str[] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void (Harl::*complain_func[]) () =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	int i = -1;
	while (++i < 4)
		if (level == complain_str[i])
			(this->*complain_func[i])();
}

void Harl::debug(void)
{
	cout << "Debug" << endl;
}

void Harl::info(void)
{
	cout << "Info" << endl;
}

void Harl::warning(void)
{
	cout << "Warning" << endl;
}

void Harl::error(void)
{
	cout << "Error" << endl;
}
