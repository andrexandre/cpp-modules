#include "PmergeMe.hpp"

int binarySearchInsertPos(const std::vector<int>& sorted, int element)
{
	int low = 0;
	int high = sorted.size();
	while (low < high)
	{
		int mid = (low + high) / 2;
		if (sorted[mid] < element)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void fjVectorSort(std::vector<int>& arr)
{
	int n = arr.size();
	
	// Passo 1: Divisão Inicial
	std::vector< std::pair<int, int> > pairs;
	for (int i = 0; i < n; i += 2) 
	{
		if (i + 1 < n)
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i], -1));
	}
	
	// Passo 2: Ordenação de Pares
	for (size_t i = 0; i < pairs.size(); ++i)
		if (pairs[i].second != -1 && pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	
	// Passo 3: Intercalação Inicial
	std::vector<int> firstElements;
	for (size_t i = 0; i < pairs.size(); ++i)
		firstElements.push_back(pairs[i].first);
	std::sort(firstElements.begin(), firstElements.end());

	// Passo 4: Inserção de Maiores
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].second != -1)
		{
			int pos = binarySearchInsertPos(firstElements, pairs[i].second);
			firstElements.insert(firstElements.begin() + pos, pairs[i].second);
		}
	}
	arr = firstElements;
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

// std::is_sorted(firstElements.begin(), firstElements.end());
// vector/deque
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
	// fjVectorSort(vec);
	std::sort(vec.begin(), vec.end());
	long long endTime = getTime();

	long long sortingTime = endTime - startTime;
	startTime = getTime();
	// fjDequeSort(deq);
	std::sort(deq.begin(), deq.end());
	endTime = getTime();

	co << "After:   ";
	printArray(vec, deq);
	co << "Time to process a range of " << ac - 1 << " elements with std::vector : " << sortingTime << " us" << nl;
	co << "Time to process a range of " << ac - 1 << " elements with std::deque  : " << endTime - startTime << " us" << nl;
	return (0);
}
