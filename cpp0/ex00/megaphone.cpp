#include <iostream>
#include <cctype>

using std::cout;
using std::endl;

int main(int ac, char** av)
{
	if (ac == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; av[i]; i++)
			for (int j = 0; av[i][j]; j++)
				cout << (char)std::toupper(av[i][j]);
	cout << endl;
	return 0;
}
