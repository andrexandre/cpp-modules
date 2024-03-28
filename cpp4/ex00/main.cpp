#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*
The virtual keyword is used when you want the compiler
to use/point to the derived class's function instead of
the base class's function
*/
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	// ...

	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();
	std::cout << wi->getType() << " " << std::endl;
	wi->makeSound();
	wmeta->makeSound();
	delete wi;
	delete wmeta;

	delete i;
	delete j;
	delete meta;
	return 0;
}
