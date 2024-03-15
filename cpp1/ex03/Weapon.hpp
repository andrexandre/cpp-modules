#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream> // std::cout
#include <string> // std::string

using std::string;
using std::endl;
using std::cout;

class Weapon
{
	public:
		Weapon(string weaponType);
		string const &getType();
		void setType(string weaponType);

	private:
		string type;
};

#endif