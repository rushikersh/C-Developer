#include <iostream>
#include <chrono>

int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	int sum = 0;

	for(int i=0; i < 10000000000; i++)
	{
		sum +=i;
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout<<"Sum : "<<sum<<std::endl;
	std::cout<<"Time taken : "<<duration<<"microsecond"<<std::endl;
	return 0;
}
