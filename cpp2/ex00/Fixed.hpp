#ifndef FIXED_HPP
# define FIXED_HPP

# define str std::string
# define co std::cout
# define nl std::endl

# include <iostream>
# include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &src);
		~Fixed();
		Fixed &operator=(Fixed const &rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _value;
		static const int _fractionalBits = 8;
};

#endif