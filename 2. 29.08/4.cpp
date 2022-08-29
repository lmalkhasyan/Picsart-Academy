#include <iostream>

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
	int i = 0;
	int sum = 0;
	while(fib(i) < 4000000)
	{
		if(!(fib(i) & 1))
		{
			sum += fib(i);
		}
		i++;
	}
	std::cout <<"Answer is: " << sum << std::endl;
	return 0;
}
