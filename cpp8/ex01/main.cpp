#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
	srand(time(0));
	for (size_t i = 0; i < 10; i++)
		cout << rand() % 10 << " ";
	cout << "\n";
	return (0);
}
