#include "Zombie.hpp"

Zombie::Zombie(string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::~Zombie()
{
	cout << name << " is dead." << endl;
}
