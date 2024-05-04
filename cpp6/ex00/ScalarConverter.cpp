#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{ *this = src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{ (void)rhs; return *this; }

int isInt(str string)
{
	char *end;
	long l = strtol(string.c_str(), &end, 10);
	if (string.length() > 12)
		return 0;
	else if (l < std::numeric_limits<int>::min() ||
		l > std::numeric_limits<int>::max())
		return 0;
	else
		return 1;
}

int checkType(const char *string)
{
	char *end;
	if (isprint(string[0]) && !string[1] && !isdigit(string[0]))
		return CHAR;
	if (isInt(string))
	{
		int i = strtol(string, &end, 10);
		if (!(*end != '\0' || errno == ERANGE))
			return INT;
		(void)i;
	}
	float f = strtof(string, &end);
	if (!(*end != 'f' || *(end + 1) != '\0' || errno == ERANGE))
		return FLOAT;
	double d = strtod(string, &end);
	if (!(*end != '\0' || errno == ERANGE))
		return DOUBLE;
	(void)f;
	(void)d;
	return -1;
}

void printChar(char c)
{
	co << "char: '" << c << "'" << nl;
	int i = static_cast<int>(c);
	co << "int: " << i << nl;
	float f = static_cast<float>(c);
	if (std::floor(f) == f)
		co << std::fixed << std::setprecision(1);
	co << "float: " << f << 'f' << nl;
	double d = static_cast<double>(c);
	if (std::floor(d) == d)
		co << std::fixed << std::setprecision(1);
	co << "double: " << d << nl;
}

void printInt(int i)
{
	if (i < 0 || i > 127)
		co << "char: impossible" << nl;
	else if (isprint(i))
		co << "char: '" << static_cast<char>(i) << "'" << nl;
	else
		co << "char: Non displayable" << nl;
	co << "int: " << i << nl;
	float f = static_cast<float>(i);
	if (std::floor(f) == f)
		co << std::fixed << std::setprecision(1);
	co << "float: " << f << 'f' << nl;
	double d = static_cast<double>(i);
	if (std::floor(d) == d)
		co << std::fixed << std::setprecision(1);
	co << "double: " << d << nl;
}

void printFloat(float f, str string)
{
	if (f < 0 || f > 127)
		co << "char: impossible" << nl;
	else if (isprint(static_cast<int>(f)))
		co << "char: '" << static_cast<char>(f) << "'" << nl;
	else
		co << "char: Non displayable" << nl;
	int i = static_cast<int>(f);
	if (isInt(string))
		co << "int: " << i << nl;
	else
		co << "int: impossible" << nl;
	if (std::floor(f) == f)
		co << std::fixed << std::setprecision(1);
	co << "float: " << f << 'f' << nl;
	double d = static_cast<double>(f);
	if (std::floor(d) == d)
		co << std::fixed << std::setprecision(1);
	co << "double: " << d << nl;
}

void printDouble(double d, str string)
{
	if (d < 0 || d > 127)
		co << "char: impossible" << nl;
	else if (isprint(static_cast<int>(d)))
		co << "char: '" << static_cast<char>(d) << "'" << nl;
	else
		co << "char: Non displayable" << nl;
	int i = static_cast<int>(d);
	if (isInt(string))
		co << "int: " << i << nl;
	else
		co << "int: impossible" << nl;
	float f = static_cast<float>(d);
	if (std::floor(f) == f)
		co << std::fixed << std::setprecision(1);
	co << "float: " << f << 'f' << nl;
	if (std::floor(d) == d)
		co << std::fixed << std::setprecision(1);
	co << "double: " << d << nl;
}

void printNanInf(int i)
{
	co << "char: impossible" << nl;
	co << "int: impossible" << nl;
	if (!i)
	{
		co << "float: nanf" << nl;
		co << "double: nan" << nl;
	}
	else if (i == 1)
	{
		co << "float: inff" << nl;
		co << "double: inf" << nl;
	}
	else
	{
		co << "float: -inff" << nl;
		co << "double: -inf" << nl;
	}
	exit(0);
}

void checkNanInf(const char *string, int n)
{
	char *end;
	if (n == FLOAT)
	{
		float f = strtof(string, &end);
		if (std::isnan(f))
			printNanInf(0);
		else if (f == -std::numeric_limits<float>::infinity())
			printNanInf(2);
		else if (std::isinf(f))
			printNanInf(1);
	}
	else if (n == DOUBLE)
	{
		double d = strtod(string, &end);
		if (std::isnan(d))
			printNanInf(0);
		else if (d == -std::numeric_limits<double>::infinity())
			printNanInf(2);
		else if (std::isinf(d))
			printNanInf(1);
	}
}

void ScalarConverter::convert(str string)
{
	const char *cstring = string.c_str();
	int type = checkType(cstring);
	checkNanInf(cstring, type);
	switch (type)
	{
		char *end;
		case CHAR:
			printChar(*cstring);
			break;
		case INT:
			printInt(strtol(cstring, &end, 10));
			break;
		case FLOAT:
			printFloat(strtof(cstring, &end), string);
			break;
		case DOUBLE:
			printDouble(strtod(cstring, &end), string);
			break;
		default:
			co << RED "Invalid type!" END << nl;
	}
}
