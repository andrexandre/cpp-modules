#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream> // std::cout
#include <string> // std::string

using std::string;
using std::endl;
using std::cout;

class	Zombie
{
	public:
		Zombie(string name);
		~Zombie();
		void	announce(void);

	private:
		string	name;
};

Zombie* newZombie(string name);
void randomChump(string name);

#endif
