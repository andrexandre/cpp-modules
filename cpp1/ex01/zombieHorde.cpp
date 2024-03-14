#include "Zombie.hpp"
// #include <sstream>
// string toString(int value)
// {
// 	stringstream ss;
// 	ss << value;
// 	return ss.str();
// }
		// string temp = name;
		// temp = name + toString(i);

Zombie* zombieHorde(int N, string name)
{
	if (N <= 0 || N > 1000000)
		return NULL;
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return horde;
}
