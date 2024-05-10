#include "Span.hpp"

Span::Span() : _size(0)
{
}

Span::Span(const Span &src) : _size(src._size)
{
	*this = src;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
		this->_inv = rhs._inv;
	return *this;
}

Span::Span(unsigned int N) : _size(N)
{
}

unsigned int Span::getSize() const
{
	return _size;
}

// void Span::addNumber(const int num)
// {
// 	if (this->_inv.size() >= this->_size ||
// 		this->_inv.size() >= this->_inv.max_size())
// 		throw Span::MaxSizeReachedException();
// 	this->_inv.push_back(num);
// }

// #include <numeric> // 
// int Span::shortestSpan(void) const
// {
// 	if (this->_inv.size() == 0) // ... < 2
// 		throw Span::EmptySpanException();

// 	std::vector<int> temp = this->_inv;
// 	std::sort(temp.begin(), temp.end());
// 	std::adjacent_difference(temp.begin(), temp.end(), temp.begin());

// 	return *std::min_element(temp.begin(), temp.end());
// }

// int Span::longestSpan(void) const
// {
// 	if (this->_inv.size() == 0) // ... < 2
// 		throw Span::EmptySpanException();

// 	int	max = *std::max_element(this->_inv.begin(), this->_inv.end());
// 	int	min = *std::min_element(this->_inv.begin(), this->_inv.end());

// 	return max - min;
// }

// void	Span::fillWithRandom(size_t num)
// {
// 	srand(time(NULL));
// 	for (size_t cur = 0; cur < num; cur++)
// 		this->addNumber(rand());
// }

// const char *Span::MaxSizeReachedException::what() const throw()
// {
// 	return "Span::MaxSizeReachedException";
// }

// const char *Span::EmptySpanException::what() const throw()
// {
// 	return "Span::EmptySpanException";
// }
