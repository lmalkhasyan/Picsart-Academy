#include <iostream>

bool is_meet(int *arr, int i)
{
	int j = 0;
	while(j < i)
	{
		if(arr[i] == arr[j])
			return false;
		j++;
	}
	return true;
}


int main()
{
	const int size = 5;
	int arr[size];

	std::cout << "Enter " << size << " Numbers:" << std::endl;
	for(int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}

	for(int i = 0, count; i < size; ++i)
	{
		if(!is_meet(arr,i))
			continue;
		std::cout << arr[i];
		count = 0;
		for(int j = i; j < size; ++j)
		{
			if(arr[i] == arr[j])
				count++;
		}
		std::cout <<": " << count << std::endl;
	}
	return 0;
}
