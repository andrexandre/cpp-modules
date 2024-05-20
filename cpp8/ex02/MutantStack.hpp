#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream>
#include <string>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &src);
		~MutantStack();
		MutantStack &operator=(const MutantStack &rhs);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

// template<typename T>
// std::ostream &operator<<(std::ostream &o, MutantStack<T> &i);

#include "MutantStack.tpp"

#endif
