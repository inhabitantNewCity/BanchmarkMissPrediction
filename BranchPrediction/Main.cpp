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

int main(int argc, char *argv[])
{	
	int executionMode;
	executionMode = atoi(argv[1]);

	std::cout << " Banchmark for calculating sum of elements" << std::endl;
	if (executionMode == 0) {
		std::cout << " withot sorting mode" << std::endl;
		std::cout << " time: " << do_branch(false) << std::endl;
	} else {
		std::cout << " sorting mode" << std::endl;
		std::cout << " time: " << do_branch(true) << std::endl;
	}
}