#ifndef DOG_HPP
#define DOG_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();
		Dog &operator=(Dog const &rhs);

		void makeSound() const;

	private:
};

#endif
