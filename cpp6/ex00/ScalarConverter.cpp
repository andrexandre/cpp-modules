#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{ *this = src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{ (void)rhs; return *this; }

int checkType(const char *string)
{
	char *end;
	if (isprint(string[0]) && !string[1] && !isdigit(string[0]))
		return CHAR;
	if (str(string).length() < 13)
	{
		long i = strtol(string, &end, 10);
		if (!(i < INT_MIN || i > INT_MAX || *end != '\0' || errno == ERANGE))
			return INT;
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

void printFloat(float f)
{
	if (f < 0 || f > 127 || std::isnan(f) || std::isinf(f))
		co << "char: impossible" << nl;
	else if (isprint(static_cast<int>(f)))
		co << "char: '" << static_cast<char>(f) << "'" << nl;
	else
		co << "char: Non displayable" << nl;
	int i = static_cast<int>(f);
	if (floor(f) < std::numeric_limits<int>::min()
	  || ceil(f) > std::numeric_limits<int>::max()
	  || std::isnan(f) || std::isinf(f))
		co << "int: impossible" << nl;
	else
		co << "int: " << i << nl;
	if (std::floor(f) == f)
		co << std::fixed << std::setprecision(1);
	co << "float: " << f << 'f' << nl;
	double d = static_cast<double>(f);
	if (std::floor(d) == d)
		co << std::fixed << std::setprecision(1);
	co << "double: " << d << nl;
}

void printDouble(double d)
{
	if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d))
		co << "char: impossible" << nl;
	else if (isprint(static_cast<int>(d)))
		co << "char: '" << static_cast<char>(d) << "'" << nl;
	else
		co << "char: Non displayable" << nl;
	int i = static_cast<int>(d);
	if (floor(d) < std::numeric_limits<int>::min()
	  || ceil(d) > std::numeric_limits<int>::max()
	  || std::isnan(d) || std::isinf(d))
		co << "int: impossible" << nl;
	else
		co << "int: " << i << nl;
	float f = static_cast<float>(d);
	if (std::floor(f) == f)
		co << std::fixed << std::setprecision(1);
	co << "float: " << f << 'f' << nl;
	if (std::floor(d) == d)
		co << std::fixed << std::setprecision(1);
	co << "double: " << d << nl;
}

void ScalarConverter::convert(str string)
{
	const char *cstring = string.c_str();
	int type = checkType(cstring);
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
			printFloat(strtof(cstring, &end));
			break;
		case DOUBLE:
			printDouble(strtod(cstring, &end));
			break;
		default:
			co << RED "Invalid type!" END << nl;
	}
}
