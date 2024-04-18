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
    Dog basic;
    {
        basic.setIdea("Basic's idea start", 0);
        Dog tmp = basic;

        tmp.printMemory();
        basic.printMemory();

        basic.setIdea("Basic's idea", 1);
        tmp.setIdea("Tmp's idea", 1);
        basic.printIdea(0);
        basic.printIdea(1);
        tmp.printIdea(0);
        tmp.printIdea(1);
    }
	return 0;
}
