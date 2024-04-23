#include <iostream> // std::cout
#include <string> // std::string
#include <fstream> // std::ifstream

using std::string;
using std::endl;
using std::cout;

string replace(string str, const string& toSearch, const string& toReplace)
{
	int i = 0;
	while (str.find(toSearch, i) != string::npos)
	{
		i = str.find(toSearch, i);
		str.erase(i, toSearch.length());
		str.insert(i, toReplace);
		i += toReplace.length();
	}
	return str;
}

int main(int ac, char** av)
{
	// parsing
	if (ac != 4)
		return (cout << "Usage: " << av[0] << " <filename> <toSearch> <toReplace>" << endl, 0);
	else if (!av[1][0] || !av[2][0] || !av[3][0])
		return (cout << "Error: empty argument" << endl, 0);

	// error checking
	std::ifstream inFile(av[1]);
	if (!inFile.is_open())
		return (cout << "Error: '" << av[1] << "' not found" << endl, 0);

	string fileName = av[1];
	fileName.append(".replace");

	std::ofstream outFile(fileName.c_str());
	if (!outFile.is_open())
		return (cout << "Error: failed to create output file" << endl, inFile.close(), 0);

	// replacing
	string line;
	while (std::getline(inFile, line))
	{
		line = replace(line, av[2], av[3]);
		outFile << line;
		if (!inFile.eof())
	 		outFile << '\n';
	}
	inFile.close();
	outFile.close();
	return 0;
}

/*
Lorem ipsum dolor sit amet, consectetur adipiscing elit.
Nulla facilisi. Sed sed nisi nisi, eu euismod justo justo.
In in commodo commodo, ut ut semper semper.
Vestibulum vestibulum lectus lectus, eu euismod mi mi.
Aliquam aliquam tincidunt tincidunt.
Mauris mauris auctor auctor, eu euismod sapien sapien.
Sed sed semper semper, eu euismod justo justo.
Nulla nulla facilisi facilisi
*/