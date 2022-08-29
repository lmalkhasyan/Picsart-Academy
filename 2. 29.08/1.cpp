#include <iostream>

int main()
{
	const int size = 10;
	int arr[size];
	int answer = 0;

	std::cout << "Enter " << size << " Numbers:" << std::endl;
	for(int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}
	for(int i = 0; i < size; ++i)
	{
		if(0 == i)
			continue ;
		if(0 == arr[i] % i)
		{
			answer++;
		}
	}
	std::cout << "Answer is: " << answer << std::endl;
	return 0;
}

