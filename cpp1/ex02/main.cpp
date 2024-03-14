#include <iostream> // std::cout
#include <string> // std::string

using std::string;
using std::cout;
using std::endl;

int	main()
{
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;

	cout << "Memory address: " << endl;
	cout << "&str: " << &str << endl;
	cout << " ptr: " << stringPTR << endl;
	cout << "&ref: " << &stringREF << endl;

	cout << "Value: " << endl;
	cout << " str: " << str << endl;
	cout << "*ptr: " << *stringPTR << endl;
	cout << " ref: " << stringREF << endl;
	return 0;
}
