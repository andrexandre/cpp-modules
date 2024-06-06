#include "BitcoinExchange.hpp"

int checkDate(str date)
{
	if (std::count(date.begin(), date.end(), '-') != 2)
		return (co << "Error: invalid date" << nl), 1;
	char *end;

	char *num = strtok((char *)date.c_str(), "-");
	if (!num || str(num).length() != 4 || num[0] == '+')
		return (co << "Error: bad 1nput" << nl), 1;
	int i = strtol(num, &end, 10);
	if (*end != '\0' || errno == ERANGE)
		return (co << "Error: bad num 1nput" << nl), 1;
	else if (i < 1 || i > 9999)
		return (co << "Error: invalid year" << nl), 1;

	num = strtok(NULL, "-");
	if (!num || str(num).length() != 2 || num[0] == '+')
		return (co << "Error: bad 2nput" << nl), 1;
	i = strtol(num, &end, 10);
	if (*end != '\0' || errno == ERANGE)
		return (co << "Error: bad num 2nput" << nl), 1;
	else if (i < 1 || i > 12)
		return (co << "Error: invalid month" << nl), 1;

	num = strtok(NULL, "-");
	if (!num || str(num).length() != 2 || num[0] == '+')
		return (co << "Error: bad 3nput" << nl), 1;
	i = strtol(num, &end, 10);
	if (*end != '\0' || errno == ERANGE)
		return (co << "Error: bad num 3nput" << nl), 1;
	else if (i < 1 || i > 31)
		return (co << "Error: invalid day" << nl), 1;
	return 0;
}

int err(const char *error_msg, bool *tmp)
{
	co << error_msg << nl;
	*tmp = true;
	return 1;
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
		if (std::count(line.begin(), line.end(), ',') != 1 &&
			err("Error: Unrecognized line", &hasError))
			continue;
		char *date = strtok((char *)line.c_str(), ",");
		if (!date && err("Error: Unrecognized line", &hasError))
			continue;
		char *value = strtok(NULL, ",");
		if ((str(date).length() != 10 || !value) &&
			err("Error: Invalid value", &hasError))
			continue;
		if (checkDate(date) && (hasError = true))
			continue;

		float f = strtof(value, &end);
		if (*end != '\0' || errno == ERANGE || f < 0)
		{
			if (f < 0)
				co << "Error: not a positive number." << nl;
			else
				co << "Error: Invalid float" << nl;
			hasError = true;
			continue;
		}
		db[date] = f;
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
		if (std::count(line.begin(), line.end(), '|') != 1 &&
			(co << "Error: bad input => " << line << nl))
			continue;
		char *date = strtok((char *)line.c_str(), " | ");
		if (!date && (co << "Error: Unrecognized line" << nl))
			continue;
		char *value = strtok(NULL, " | ");
		if ((str(date).length() != 10 || !value) &&
			(co << "Error: Invalid value" << nl))
			continue;
		if (checkDate(date))
			continue;

		float f = strtof(value, &end);
		if (*end != '\0' || errno == ERANGE || f < 0 || f > 1000)
		{
			if (f < 0)
				co << "Error: not a positive number." << nl;
			else if (f > 1000)
				co << "Error: too large a number." << nl;
			else
				co << "Error: Invalid float" << nl;
			continue;
		}
		float res = searchDB(db, date);
		if (res == -1)
			co << "Error: invalid date" << nl;
		else
			co << date << " => " << f << " = " << res * f << nl;
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
		return (co << "Error: could not open file." << nl), 0;
	searchFile(inputFile, db);
	inputFile.close();
	return (0);
}
