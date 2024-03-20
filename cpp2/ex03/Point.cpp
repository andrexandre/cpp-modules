#include "Point.hpp"

Point::Point() : _x (0) , _y (0)
{
}

Point::Point(const Point &src)
{
	*this = src;
}

Point::~Point()
{
}

Point &Point::operator=(Point const &rhs)
{
	if (this != &rhs)
	{
		(Fixed &)this->_x = rhs.getPoint('x');
		(Fixed &)this->_y = rhs.getPoint('y');
	}	
	return *this;
}

Point::Point(Fixed const x, Fixed const y) : _x(x) , _y(y)
{
}

float Point::getPoint(char coord) const
{
	if (coord == 'x')
		return this->_x.toFloat();
	else if (coord == 'y')
		return this->_y.toFloat();
	return 0;
}
