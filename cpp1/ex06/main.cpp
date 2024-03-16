#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2 || !av[1][0])
	{
		cout << "Usage: " << av[0] << " <log level>" << endl;
		return 0;
	}
	Harl harl;
	harl.complain(av[1]);
	return 0;
}
