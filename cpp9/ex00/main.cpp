#include "BitcoinExchange.hpp"

std::map<str, float> createDB(std::ifstream &dbFile)
{
	std::map<str, float> db;
	str line;
	char *ptr;
	char *end;
	std::getline(dbFile, line);
	while (std::getline(dbFile, line))
	{
		co << "line: " << line << nl;
		int commaCount = std::count(line.begin(), line.end(), ',');
		if (commaCount != 1)
		{
			co << " ptr: " << commaCount << " commas" << nl;
			continue;
		}
			// return (db.clear()), db;
		ptr = strtok((char *)line.c_str(), ",");
		if (ptr)
		{
			db[ptr] = std::strtof(strtok(NULL, ","), &end);
			co << " ptr: " << ptr << ", f: " << db[ptr] << nl;
		}
		else
			co << " ptr: error" << nl;
			// return (db.clear()), db;
	}
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
	if (db.empty())
		return (co << "Corrupted database." << nl), 0;
	dbFile.close();
	std::ifstream inputFile(av[1]);
	if (!inputFile.is_open())
		return (co << "Error: could not open file." << nl), 0;
	inputFile.close();
	co << "Everything correct 💀" << nl;
	return (0);
}

/*
Parsing:
open data.csv
Year-Month-Day | value
strtok by ,

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
