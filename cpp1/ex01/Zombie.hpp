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
		Zombie(void);
		Zombie(string name);
		~Zombie();
		void	setName(string name);
		void	announce(void);

	private:
		string	name;
};

Zombie* zombieHorde(int N, string name);

#endif
