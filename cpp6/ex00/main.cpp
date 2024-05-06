#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
		co << RED "Invalid arguments" END << nl;
	else
		ScalarConverter::convert(str(av[1]));
	return (0);
}

/*
cat << EOF > test.sh
#!/bin/bash
EXEC='./convert'
# EXEC='valgrind ./convert'

make

echo -e "\033[34m"Testing Invalid arguments "\033[0m"
$EXEC
$EXEC ""
$EXEC qwe
echo

echo -e "\033[34m"Testing char "\033[0m"
$EXEC q
$EXEC 0
$EXEC 5
echo

echo -e "\033[34m"Testing int "\033[0m"
$EXEC 42
$EXEC +42
$EXEC -42
echo

echo -e "\033[34m"Testing float "\033[0m"
$EXEC 42f
$EXEC 42.f
$EXEC 42.0f
$EXEC 42.5f
echo
$EXEC +42f
$EXEC +42.f
$EXEC +42.0f
$EXEC +42.5f
echo
$EXEC -42f
$EXEC -42.f
$EXEC -42.0f
$EXEC -42.5f
echo

echo -e "\033[34m"Testing double "\033[0m"
$EXEC 42.
$EXEC 42.0
$EXEC 42.5
echo
$EXEC +42.
$EXEC +42.0
$EXEC +42.5
$EXEC -42.
$EXEC -42.0
$EXEC -42.5

echo
echo -e "\033[34m"Testing nan/inf "\033[0m"
$EXEC nanf
$EXEC inff
$EXEC +inff
$EXEC -inff
echo
$EXEC nan
$EXEC inf
$EXEC +inf
$EXEC -inf
EOF
chmod +x test.sh
*/