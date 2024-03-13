#include "Zombie.hpp"

int	main()
{
	randomChump("Chump");

	Zombie*	zombie = newZombie("Zombie");
	delete zombie;
	return 0;
}
