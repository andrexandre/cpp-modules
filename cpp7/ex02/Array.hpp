#ifndef ARRAY_HPP
#define ARRAY_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream>
#include <string>

template<typename T>
class Array
{
	public:
		Array();
		Array(const Array &src);
		~Array();
		Array &operator=(const Array &rhs);

		Array(unsigned int n);
		T& operator[](unsigned int index);
		unsigned int	size(void) const;

	private:
		unsigned int _size;
		T *_node;
};

#endif
