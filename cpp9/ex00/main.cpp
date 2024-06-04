#include "BitcoinExchange.hpp"

void checkDate(str date)
{
	int minusCount = std::count(date.begin(), date.end(), '-');
	if (minusCount != 2)
		co << "Error: invalid date" << nl;
	char *num = strtok((char *)date.c_str(), "-");
	char *end;
	int i = strtol(num, &end, 10);
	if (*end != '\0' || errno == ERANGE)
		co << "Error: bad input => " << date << nl;
	(void)i;
}

std::map<str, float> createDB(std::ifstream &dbFile)
{
	std::map<str, float> db;
	bool hasError = false;
	str line;
	char *end;
	std::getline(dbFile, line);
	while (std::getline(dbFile, line))
	{
		// co << "line: " << line << nl;
		if (std::count(line.begin(), line.end(), ',') != 1)
		{
			co << "Error: Unrecognized line" << nl;
			hasError = true;
			continue;
		}
		char *date = strtok((char *)line.c_str(), ",");
		if (!date)
		{
			co << "Error: Unrecognized line" << nl;
			hasError = true;
			continue;
		}
		char *value = strtok(NULL, ",");
		checkDate(date);
		if (str(date).length() > 10 || !value)
		{
			co << "Error: Invalid value" << nl;
			hasError = true;
			continue;
		}
		float f = strtof(value, &end);
		if (*end != '\0' || errno == ERANGE || f < 0 || f > 1000)
		{
			if (f < 0)
				co << "Error: not a positive number." << nl;
			else if (f > 1000)
				co << "Error: too large a number." << nl;
			else
				co << "Error: Invalid float" << nl;
			hasError = true;
			continue;
		}
		db[date] = f;
		co << date << " => " << db[date] << nl;
	}
	if (hasError)
		return (db.clear()), db;
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
		return (co << "Corrupted database 💀" << nl), 0;
	dbFile.close();
	std::ifstream inputFile(av[1]);
	if (!inputFile.is_open())
		return (co << "Error: could not open file." << nl), 0;
	inputFile.close();
	co << "Everything correct ✅" << nl;
	return (0);
}

/*
Parsing:
open data.csv
Year-Month-Day | value
strtok by ","

strtok by " | "
check size is not 2

strtok by "-"
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
