#include <iostream>

int main()
{
	const int size = 5;
	int arr[size];
	int even = 0;
	int odd = 0;
	std::cout << "Enter " << size << " Numbers:" << std::endl;
	for(int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}

	for(int i = 0; i < size; ++i)
	{
		if(arr[i] & 1 && odd == 0)
			odd = 1;
		if(arr[i] & 1)
			odd *= arr[i];
		else
			even += arr[i];
	}
		std::cout <<"Answer is: " << even - odd << std::endl;
	return 0;
}
