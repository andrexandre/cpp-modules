#ifndef BRAIN_HPP
#define BRAIN_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "AAnimal.hpp"

class Brain
{
	public:
		Brain();
		Brain(Brain const &src);
		~Brain();
		Brain &operator=(Brain const &rhs);

        str* getIdeas();
        void setIdea(str idea, int index);
        void printIdea(int index);

	private:
		str ideas[100];
};

#endif
