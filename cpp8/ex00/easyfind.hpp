#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, int target)
{
	return std::find(container.begin(), container.end(), target);
}

#endif
