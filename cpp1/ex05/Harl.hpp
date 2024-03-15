#ifndef HARL_HPP
#define HARL_HPP

#include <iostream> // std::cout
#include <string> // std::string
#include <fstream> // std::ifstream

using std::string;
using std::endl;
using std::cout;

class Harl
{
	public:
		void complain(string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif