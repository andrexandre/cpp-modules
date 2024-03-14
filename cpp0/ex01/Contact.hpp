#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip> // std::setw
#include <iostream> // std::cout
#include <string> // std::string

using std::string;
using std::endl;
using std::cout;

class	Contact
{
	public:
		string	get_name(int i);
		void	set_name(int i, string str);

	private:
		string	name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;
};

#endif
