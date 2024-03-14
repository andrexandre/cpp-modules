#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "Zombie";
}

Zombie::Zombie(string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	cout << name << " is dead." << endl;
}

void	Zombie::setName(string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}
