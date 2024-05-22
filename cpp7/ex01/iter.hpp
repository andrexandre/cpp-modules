#ifndef ITER_HPP
#define ITER_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream>
#include <string>

template<typename T, typename F>
void iter(T *array, size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif