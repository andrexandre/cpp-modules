#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

typedef AAnimal Animal;

int main()
{
	// Animal test;
	int length = 4;
	Animal *herd[length];
	for (int i = 0; i < length; i++)
	{
		if (i < length / 2)
			herd[i] = new Dog();
		else
			herd[i] = new Cat();
	}
	for (int i = 0; i < length; i++)
		herd[i]->makeSound();
	for (int i = 0; i < length; i++)
		delete herd[i];

	co << nl;
	Dog basic;
	{
		Dog tmp = basic;
		Dog tmp2 = Dog(basic);
	}
	return 0;
}
