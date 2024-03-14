#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream> // std::cout
#include <string> // std::string

using std::string;
using std::endl;
using std::cout;
using std::cin;

class Weapon
{
	public:
		Weapon(string type);
		string const &getType();
		void setType(string type);

	private:
		string type;
};

#endif
