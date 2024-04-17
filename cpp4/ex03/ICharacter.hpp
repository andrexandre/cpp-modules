#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string

class AMateria;

class ICharacter
{
	public:
		ICharacter();
		ICharacter(ICharacter const &src);
		ICharacter &operator=(ICharacter const &rhs);

		virtual ~ICharacter() {}
		virtual std::string const &getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
