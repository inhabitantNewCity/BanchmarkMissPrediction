#include <algorithm>
#include <ctime>
#include <iostream>

double do_branch(bool sorting, bool cond_assign) {
	const unsigned arraySize = 32768;
	int data[arraySize];

	for (unsigned c = 0; c < arraySize; ++c)
		data[c] = std::rand() % 256;

	if(sorting)
		std::sort(data, data + arraySize);

	
	clock_t start = clock();
	long long sum = 0;

	for (unsigned i = 0; i < 10000; ++i)
	{
		for (unsigned c = 0; c < arraySize; ++c)
		{
			if (cond_assign) {
				sum += data[c] >= 128 ? data[c] : 0;
			}
			else {
				if (data[c] >= 128)
					sum += data[c];
			}
		}
	}

	return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
}

int main()
{	
	std::cout << " Banchmark for calculating sum of elements" << std::endl;

	double NonSortAndNonCond = do_branch(false, false);
	std::cout << " time without Sort And Cond " << NonSortAndNonCond << std::endl;
	
	double SortAndNonCond = do_branch(true, false);
	std::cout << " time with Sort but without Cond " << SortAndNonCond << std::endl;

	double NonSortAndCond = do_branch(false, true);
	std::cout << " time without Sort but with Cond " << NonSortAndCond << std::endl;

	double SortAndCond = do_branch(true, true);
	std::cout << " time with Sort And Cond " << SortAndCond << std::endl;

	getchar();
}