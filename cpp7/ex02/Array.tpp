#include "Array.hpp"

template<typename T>
Array<T>::Array() : _size(0), _node(NULL)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _node(new T[n])
{
}

template<typename T>
Array<T>::Array(const Array<T> &src)
{
	*this = src;
}

template<typename T>
Array<T>::~Array()
{
	if (_node != NULL)
	{
		delete[] _node;
		_node = 0;
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs)
{
	if (this != &rhs)
	{
		this->_size = rhs._size;
		this->_node = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_node[i] = rhs._node[i];		
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out_of_range");
	return _node[index];
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}
