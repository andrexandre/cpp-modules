#ifndef CAT_HPP
#define CAT_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();
		Cat &operator=(Cat const &rhs);

		void makeSound() const;

        void setIdea(str idea, int index);
        void printIdea(int index);
		void printMemory() const;
	private:
		Brain *brain;
};

#endif
