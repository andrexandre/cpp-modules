#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
}

IMateriaSource::IMateriaSource(const IMateriaSource &src)
{
	*this = src;
}

IMateriaSource &IMateriaSource::operator=(IMateriaSource const &rhs)
{
	if (this != &rhs)
		(void)rhs;
	return *this;
}

