#include <iostream> // std::cout
#include <string> // std::string

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory address: " << std::endl;
	std::cout << "&str: " << &str << std::endl;
	std::cout << " ptr: " << stringPTR << std::endl;
	std::cout << "&str: " << &stringREF << std::endl;

	std::cout << "Value: " << std::endl;
	std::cout << " str: " << str << std::endl;
	std::cout << "*ptr: " << *stringPTR << std::endl;
	std::cout << " ref: " << stringREF << std::endl;
	return 0;
}
