#include "Zombie.hpp"

// using namespace

int	main()
{
	randomChump("Chump");

	Zombie*	zombie = newZombie("Zombie");
	delete zombie;
	return 0;
}
