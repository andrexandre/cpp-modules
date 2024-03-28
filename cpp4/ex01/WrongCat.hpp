#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const &src);
		~WrongCat();
		WrongCat &operator=(WrongCat const &rhs);

		void makeSound() const;

	private:
};

#endif
