#ifndef ICE_HPP
#define ICE_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &src);
		~Ice();
		Ice &operator=(Ice const &rhs);

		Ice* clone() const;
		void use(ICharacter& target);
};

#endif
