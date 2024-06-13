#include "PmergeMe.hpp"

void fjVectorSort(std::vector<int> &arr)
{
	size_t size = arr.size();
	if (size <= 1)
		return;

	std::vector<int> lesser, greater;
	for (size_t i = 0; i < size - 1; i += 2)
	{
		if (arr[i] < arr[i + 1])
		{
			lesser.push_back(arr[i]);
			greater.push_back(arr[i + 1]);
		}
		else
		{
			lesser.push_back(arr[i + 1]);
			greater.push_back(arr[i]);
		}
	}
	if (size % 2 != 0)
		lesser.push_back(arr.back());

	fjVectorSort(lesser);
	for (size_t i = 0; i < greater.size(); ++i)
		lesser.insert(std::upper_bound(lesser.begin(), lesser.end(), greater[i]), greater[i]);
	arr = lesser;
	// std::swap(arr[0], arr[1]);
}

void fjDequeSort(std::deque<int> &arr)
{
	size_t size = arr.size();
	if (size <= 1)
		return;

	std::deque<int> lesser, greater;
	for (size_t i = 0; i < size - 1; i += 2)
	{
		if (arr[i] < arr[i + 1])
		{
			lesser.push_back(arr[i]);
			greater.push_back(arr[i + 1]);
		}
		else
		{
			lesser.push_back(arr[i + 1]);
			greater.push_back(arr[i]);
		}
	}
	if (size % 2 != 0)
		lesser.push_back(arr.back());

	fjDequeSort(lesser);
	for (size_t i = 0; i < greater.size(); ++i)
		lesser.insert(std::upper_bound(lesser.begin(), lesser.end(), greater[i]), greater[i]);
	arr = lesser;
}

void printArray(std::vector<int> &vec, std::deque<int> &deq)
{
	for (size_t i = 0; i < vec.size() && i < 5; ++i)
	{
		if (vec[i] != deq[i])
			return (co << "The containers do not contain the same items" << nl), (void)0;
		co << vec[i] << " ";
	}
	if (vec.size() > 5)
		co << "[...]";
	co << nl;
}

int parseAndBuild(int ac, char **&av, std::vector<int> &vec, std::deque<int> &deq)
{
	for (int i = 1; i < ac; i++)
	{
		char *end;
		int n = strtol(av[i], &end, 10);
		if (*end != '\0' || errno == ERANGE || n < 1 || n > INT_MAX)
			return 1;
		vec.push_back(n);
		deq.push_back(n);
	}
	return 0;
}

long long getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000000LL + tv.tv_usec;
}

// vector is an array and deque is a linked list
// so the vector is faster because it stores its
// elements in a contiguous block of memory
int main(int ac, char **av)
{
	if (ac == 1)
		return (co << "./PmergeMe <array>" << nl), 0;
	std::vector<int> vec;
	std::deque<int> deq;
	if (parseAndBuild(ac, av, vec, deq))
		return (co << "Error" << nl), 0;

	co << "Before:  ";
	printArray(vec, deq);
	long long startTime = getTime();
	fjVectorSort(vec);
	long long endTime = getTime();

	long long sortingTime = endTime - startTime;
	startTime = getTime();
	fjDequeSort(deq);
	endTime = getTime();

	co << "After:   ";
	printArray(vec, deq);
	co << "Time to process a range of " << ac - 1 << " elements with std::vector : " << sortingTime << " us" << nl;
	co << "Time to process a range of " << ac - 1 << " elements with std::deque  : " << endTime - startTime << " us" << nl;
	return (0);
}
