#include "easyfind.hpp"

template<typename T>
void easyfill(T &container, int size, int rangeOfNum)
{
	srand(time(NULL));
	co << "Index: ";
	for (int i = 0; i < size; i++)
		container.push_back(rand() % rangeOfNum);
	for (int i = 0; i < size; i++)
		co << i << " ";
	co << nl;
}

template<typename T>
void easyprint(T& container)
{
	co << "Value: ";
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		co << *it << " ";
	co << nl;
}

template<typename T>
void easytest(T& container, int numToFind, str string)
{
	co << "Testing " << string << nl;
	easyfill(container, 10, 10);
	easyprint(container);
	typename T::iterator it = easyfind(container, numToFind);
	int index = std::distance(container.begin(), it);
	if (it != container.end())
	{
		co << "       ";
		for (int i = 0; i < index; i++)
			co << "  ";
		co << "^";
	}
	co << nl << "Result: ";
	if (it != container.end())
		co << "Found at index " << index << "!" << nl;
	else
		co << "Not found!" << nl;
	co << END;
}

int main()
{
	int numToFind = rand() % 10;
	co << "Trying to find number " << numToFind << nl;

	co << GREEN << nl;
	std::vector<int> vec;
	easytest(vec, numToFind, "vector");

	co << BLUE << nl;
	std::list<int> lst;
	easytest(lst, numToFind, "list");

	co << RED << nl;
	std::deque<int> deq;
	easytest(deq, numToFind, "deque");

	return (0);
}
