#include "Fixed.hpp"

Fixed::Fixed()
{
	co << "Default constructor called" << nl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &src)
{
	co << "Copy constructor called" << nl;
	*this = src;
}

Fixed::~Fixed()
{
	co << "Destructor called" << nl;
}

// rhs = right hand side
Fixed &Fixed::operator=(Fixed const &rhs)
{
	co << "Copy assignment operator called" << nl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	co << "getRawBits member function called" << nl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	co << "setRawBits member function called" << nl;
	this->_value = raw;
}