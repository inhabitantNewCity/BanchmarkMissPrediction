#include <algorithm>
#include <ctime>
#include <iostream>

double do_branch(bool sorting) {
	const unsigned arraySize = 32768;
	int data[arraySize];

	for (unsigned c = 0; c < arraySize; ++c)
		data[c] = std::rand() % 256;

	if(sorting)
		std::sort(data, data + arraySize);

	
	clock_t start = clock();
	long long sum = 0;

	for (unsigned i = 0; i < 100000; ++i)
	{
		for (unsigned c = 0; c < arraySize; ++c)
		{

				if (data[c] >= 128)
					sum += data[c];
		}
	}

	return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
}

int main()
{	
	std::cout << " Banchmark for calculating sum of elements" << std::endl;

	double NonSortAndNonCond = do_branch(false);
	std::cout << " time without Sort: " << NonSortAndNonCond << std::endl;
	
	double SortAndNonCond = do_branch(true);
	std::cout << " time with Sort: " << SortAndNonCond << std::endl;

	getchar();
}