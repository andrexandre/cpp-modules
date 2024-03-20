#ifndef POINT_HPP
#define POINT_HPP

# define str std::string
# define co std::cout
# define nl std::endl

#include <iostream> // std::cout
#include <string> // std::string
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(Point const &src);
		~Point();
		Point &operator=(Point const &rhs);

		Point(Fixed const x, Fixed const y);
		float getPoint(char coord) const;

	private:
		Fixed const _x;
		Fixed const _y;
};

#endif
