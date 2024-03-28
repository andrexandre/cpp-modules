#ifndef CAT_HPP
#define CAT_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();
		Cat &operator=(Cat const &rhs);

		void makeSound() const;

	private:
		Brain *brain;
};

#endif
