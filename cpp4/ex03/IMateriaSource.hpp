#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		IMateriaSource();
		IMateriaSource(IMateriaSource const &src);
		IMateriaSource &operator=(IMateriaSource const &rhs);

		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
