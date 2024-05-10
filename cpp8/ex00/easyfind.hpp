#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define SIZE 10
#define ERROR_STR "bro's cookin 💀"
#define END     "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>

template<typename T>
typename T::iterator easyfind(T &container, int target)
{
	return std::find(container.begin(), container.end(), target);
}

#endif
