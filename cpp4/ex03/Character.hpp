#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(Character const &src);
		~Character();
		Character &operator=(Character const &rhs);

		Character(str name);
		virtual std::string const &getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private:
		static const int	_invSize = 4;
		AMateria *_inventory[_invSize];
		str _name;
};

#endif
