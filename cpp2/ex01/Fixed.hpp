#ifndef FIXED_HPP
# define FIXED_HPP

# define str std::string
# define co std::cout
# define nl std::endl

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &src);
		~Fixed();
		Fixed &operator=(Fixed const &rhs);

		Fixed(int const value);
		Fixed(float const value);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		
	private:
		int _value;
		static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif