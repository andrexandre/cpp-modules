#include "Zombie.hpp"

// using namespace

int	main()
{
	Zombie*	zombie = newZombie("Zombie");
	zombie->announce();
	delete zombie;

	randomChump("Chump");
	return 0;
}
