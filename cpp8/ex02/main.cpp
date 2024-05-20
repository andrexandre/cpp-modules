#include "MutantStack.hpp"

// Using iterators in the stack is dumb because directly accessing
// the underlying container of std::stack can break the encapsulation
// of std::stack. Encapsulation means interacting with it only through
// its public interface. This ensures that the std::stack can maintain
// its internal state correctly
int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	// co << nl;
	// MutantStack<int> mstack1;
	// MutantStack<int> mstack2;

	// mstack1.push(5);
	// mstack1.push(17);
	// co << "mstack1:" << nl << mstack1;

	// mstack2 = mstack1;
	// mstack1.pop();
	// co << "mstack2:" << nl << mstack2;

	// MutantStack<int> mstack3(mstack2);
	// mstack1.pop();
	// co << "mstack3:" << nl << mstack3;

	return 0;
}

// #include <list>
// int main()
// {
// 	std::list<int> list;

// 	list.push_back(5);
// 	list.push_back(17);

// 	std::cout << list.back() << std::endl;

// 	list.pop_back();

// 	std::cout << list.size() << std::endl;

// 	list.push_back(3);
// 	list.push_back(5);
// 	list.push_back(737);
// 	//[...]
// 	list.push_back(0);

// 	std::list<int>::iterator it = list.begin();
// 	std::list<int>::iterator ite = list.end();

// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::list<int> l(list);
// 	return 0;
// }
