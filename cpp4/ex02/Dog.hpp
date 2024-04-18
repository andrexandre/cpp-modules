#ifndef DOG_HPP
#define DOG_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();
		Dog &operator=(Dog const &rhs);

		void makeSound() const;

        void setIdea(str idea, int index);
        void printIdea(int index);
		void printMemory() const;
	private:
		Brain *brain;
};

#endif
