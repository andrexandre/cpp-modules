#include "BitcoinExchange.hpp"

std::map<str, float> createDB(std::ifstream &dbFile)
{
	std::map<str, float> db;
	// str line = NULL;
	// while (std::getline(dbFile, line))
	// {		
	// 	// char *ptr = strtok((char *)line.c_str(), ",");
	// }
	(void)dbFile;
	return db;
}

// why use map? bcs maps have key/value pairs or better search and remove duplicates
int main(int ac, char **av)
{
	if (ac != 2)
		return (co << "Error: could not open file." << nl), 0;
	std::ifstream dbFile(DB_LOCATION);
	if (!dbFile.is_open())
		return (co << "Error: could not open db." << nl), 0;
	std::map<str, float> db = createDB(dbFile);
	dbFile.close();
	std::ifstream inputFile(av[1]);
	if (!inputFile.is_open())
		return (co << "Error: could not open file." << nl), 0;
	inputFile.close();
	return (0);
}

/*
Parsing:
open data.csv
Year-Month-Day | value
// strtok by ,

strtok by |
check size is not 2

strtok by -
check size is not 3
check if str is bigger than 10 char
check if its negative or bigger than normal date

check if its float/double
check if its negative
store all that sh on a map

Outputting:
open input.txt
print in format:
Year-Month-Day => value = (value * exchange rate)
Ex.: 2011-01-03 => 1 = 0.3
If date not exist -> use the lower date.
*/
// map, stack, vector/deque
