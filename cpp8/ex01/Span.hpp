#ifndef SPAN_HPP
#define SPAN_HPP

#define str std::string
#define co std::cout
#define nl std::endl

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>

class Span
{
	public:
		Span();
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &rhs);

		Span(unsigned int N);
		unsigned int getSize() const;
		// void addNumber(const int num);
		// int shortestSpan(void) const;
		// int longestSpan(void) const;
		// void fillWithRandom(size_t num);

		// class MaxSizeReachedException : public std::exception
		// {
		// 	public:
		// 		virtual const char *what() const throw();
		// };
		// class EmptySpanException : public std::exception
		// {
		// 	public:
		// 		virtual const char *what() const throw();
		// };

	private:
		std::vector<int> _inv;
		unsigned int _size;
};

#endif
