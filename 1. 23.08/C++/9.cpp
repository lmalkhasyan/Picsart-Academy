#include <iostream>

void print_num_sum(int a)
{
	int sum = 0;
	while (a)
	{
		sum += (a % 10);
		a /= 10;
	}
	std::cout << "SUM of digits is: " << sum << std::endl;
}

int main()
{
	int a;
	std::cin >> a;
	print_num_sum(a);
	return 0;
}

