#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria(AMateria const &src);
		~AMateria();
		AMateria &operator=(AMateria const &rhs);

		AMateria(std::string const &type);
		// [...]

		std::string const &getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		str _type;
};

#endif
