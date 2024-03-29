#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(Character const &src);
		~Character();
		Character &operator=(Character const &rhs);

	private:
};

#endif
