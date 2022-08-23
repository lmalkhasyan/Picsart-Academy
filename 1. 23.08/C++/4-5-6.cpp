#include <iostream>

int main()
{
	for(int i = 0; i<=100; ++i)
	{
		std::cout<< i << "_";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for(int i = 0; i<=100; i+=2)
	{
		std::cout<<i << "_";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for(int i = 1; i<=99; i+=2)
	{
		std::cout<<i << "_";
	}
	return 0;
}
