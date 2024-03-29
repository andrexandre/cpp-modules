#ifndef CURE_HPP
#define CURE_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &src);
		~Cure();
		Cure &operator=(Cure const &rhs);

		Cure* clone() const;

	private:
};

#endif
