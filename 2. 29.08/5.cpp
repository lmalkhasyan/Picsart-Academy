#include <iostream>

void swap(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int main()
{
	const int size = 5;
	int arr[size];
	int even = 0;
	int odd = 1;
	std::cout << "Enter " << size << " Numbers:" << std::endl;
	for(int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}

	for(int i = 0; i < size - 1; ++i)
	{
		for(int i = 1; i < size; ++i)
		{
			if(arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
			}
		}
	}

	for(int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
	return 0;
}
