#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
		co << RED "Invalid arguments" END << nl;
	else
		ScalarConverter::convert(str(av[1]));
	return (0);
}
