#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src)
{
	*this = src;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &rhs)
{
	this->c = rhs.c;
	return *this;
}

// the c in this->c.begin is the container in the stack
template<class T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

// this function can't be used in empty stacks
// template<typename T>
// std::ostream &operator<<(std::ostream &o, MutantStack<T> &i)
// {
// 	for (typename MutantStack<T>::iterator it = i.begin(); it != i.end(); it++)
// 		o << *it << nl;
// 	return o;
// }
