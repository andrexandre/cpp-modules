#include "BitcoinExchange.hpp"

void checkDate(str date)
{
	if (std::count(date.begin(), date.end(), '-') != 2)
		throw "Error: invalid date";
	char *end;

	char *num = strtok((char *)date.c_str(), "-");
	if (!num || str(num).length() != 4 || num[0] == '+')
		throw "Error: bad 1nput";
	int i = strtol(num, &end, 10);
	if (*end != '\0' || errno == ERANGE)
		throw "Error: bad num 1nput";
	else if (i < 1 || i > 9999)
		throw "Error: invalid year";

	num = strtok(NULL, "-");
	if (!num || str(num).length() != 2 || num[0] == '+')
		throw "Error: bad 2nput";
	i = strtol(num, &end, 10);
	if (*end != '\0' || errno == ERANGE)
		throw "Error: bad num 2nput";
	else if (i < 1 || i > 12)
		throw "Error: invalid month";

	num = strtok(NULL, "-");
	if (!num || str(num).length() != 2 || num[0] == '+')
		throw "Error: bad 3nput";
	i = strtol(num, &end, 10);
	if (*end != '\0' || errno == ERANGE)
		throw "Error: bad num 3nput";
	else if (i < 1 || i > 31)
		throw "Error: invalid day";
}

std::map<str, float> createDB(std::ifstream &dbFile)
{
	std::map<str, float> db;
	bool hasError = false;
	str line;
	char *end;
	std::getline(dbFile, line);
	if (line != "date,exchange_rate")
		co << "Error: first line is not \"date,exchange_rate\"" << nl;
	while (std::getline(dbFile, line))
	{
		try
		{
			if (std::count(line.begin(), line.end(), ',') != 1)
				throw "Error: Unrecognized line";
			char *date = strtok((char *)line.c_str(), ",");
			if (!date)
				throw "Error: Unrecognized line";
			char *value = strtok(NULL, ",");
			if (str(date).length() != 10 || !value)
				throw "Error: Invalid value";
			checkDate(date);

			float f = strtof(value, &end);
			if (*end != '\0' || errno == ERANGE)
				throw "Error: Invalid float";
			if (f < 0)
				throw "Error: not a positive number.";
			db[date] = f;
		}
		catch(char const *err_msg)
		{
			co << err_msg << nl;
			hasError = true;
		}
	}
	if (hasError)
		return (db.clear()), db;
	return db;
}

// lower_bound returns an iterator to the first element with a key equal or greater than date
float searchDB(std::map<str, float>& db, str date)
{
	std::map<str, float>::iterator it = db.lower_bound(date);
	if (it->first != date && it != db.begin())
		--it;
	else if (it == db.begin())
		return -1;
	return it->second;
}

void searchFile(std::ifstream &inputFile, std::map<str, float> db)
{
	str line;
	char *end;
	std::getline(inputFile, line);
	if (line != "date | value")
		co << "Error: first line is not \"date | value\"" << nl;
	while (std::getline(inputFile, line))
	{
		try
		{
			if (std::count(line.begin(), line.end(), '|') != 1)
			{
				co << "Error: bad input => " + line << nl;
				continue;
			}
			char *date = strtok((char *)line.c_str(), " | ");
			if (!date)
				throw "Error: Unrecognized line";
			char *value = strtok(NULL, " | ");
			if (str(date).length() != 10 || !value)
				throw "Error: Invalid value";
			checkDate(date);

			float f = strtof(value, &end);
			if (*end != '\0' || errno == ERANGE)
				throw "Error: Invalid float";
			if (f < 0)
				throw "Error: not a positive number.";
			if (f > 1000)
				throw "Error: too large a number.";
			float res = searchDB(db, date);
			if (res == -1)
				throw "Error: invalid date";
			co << date << " => " << f << " = " << res * f << nl;
		}
		catch(char const *err_msg)
		{
			co << err_msg << nl;
		}
	}
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
	if (db.empty())
		return (co << "Invalid database 💀" << nl), 0;

	std::ifstream inputFile(av[1]);
	if (!inputFile.is_open())
		return (co << "Error: could not input file." << nl), 0;
	searchFile(inputFile, db);
	inputFile.close();
	return (0);
}
