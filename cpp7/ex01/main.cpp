#include "iter.hpp"

template <typename T>
void print( T &i )
{
	co << i << nl;
}

int main(void)
{
	int length = 5;

	int arr1[] = { 1, 2, 3, 4, 5 };
	co << "int arr1: " << nl;
	iter(arr1, length, print<int>);

	double arr2[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	co << nl << "double arr2: " << nl;
	iter(arr2, length, print<double>);

	char arr3[] = { 'a', 'b', 'c', 'd', 'e' };
	co << nl << "char arr3: " << nl;
	iter(arr3, length, print<char>);

	str arr4[] = { "one", "two", "three", "four", "five" };
	co << nl << "str arr4: " << nl;
	iter(arr4, length, print<str>);

	return (0);
}
