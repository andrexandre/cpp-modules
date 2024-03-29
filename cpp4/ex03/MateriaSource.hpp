#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &src);
		~MateriaSource();
		MateriaSource &operator=(MateriaSource const &rhs);

	private:
};

#endif
