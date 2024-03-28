#ifndef BRAIN_HPP
#define BRAIN_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "Animal.hpp"

class Brain
{
	public:
		Brain();
		Brain(Brain const &src);
		~Brain();
		Brain &operator=(Brain const &rhs);

	private:
		str ideas[100];
};

#endif
