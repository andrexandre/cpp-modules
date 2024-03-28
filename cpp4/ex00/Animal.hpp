#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string

class Animal
{
	public:
		Animal();
		Animal(Animal const &src);
		virtual ~Animal();
		Animal &operator=(Animal const &rhs);

		str getType() const;
		void setType(str type);
		virtual void makeSound() const;

	protected:
		str type;
};

#endif
