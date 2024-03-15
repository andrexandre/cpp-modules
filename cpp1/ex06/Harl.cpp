#include "Harl.hpp"

// NO IF/ELSE STATEMENTS

void Harl::complain(string level)
{
	string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++ ;
	switch (i)
	{
		default:
			cout << "[ Probably complaining about insignificant problems ]" << endl;
			break;
		case 0:
			this->debug();
			// fall through
		case 1:
			this->info();
			// fall through
		case 2:
			this->warning();
			// fall through
		case 3:
			this->error();
	}
}

void Harl::debug(void)
{
	cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n\n";
}

void Harl::info(void)
{
	cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n\n";
}

void Harl::warning(void)
{
	cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error(void)
{
	cout << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now.\n\n";
}
