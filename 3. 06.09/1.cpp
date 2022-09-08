#include <iostream>

size_t strlen(const char *str)
{
	if(!str)
		return 0;

	size_t len = 0;
	while(str[len])
		++len;
	return len;
}

int binary_search(int *arr, int size, int num)
{
	if(!arr)
		return -1;

	int left = 0;
	int right = size - 1;
	int middle;

	while(left <= right)
	{
		middle = (left + right) / 2;
		if(arr[middle] < num)
			left = middle + 1;
		else if(arr[middle] > num)
			right = middle - 1;
		else
			return middle;
	}
	return -1;
}

int binary_search_rec(int *arr, int start, int end, int num)
{
	if (start > end)
		return -1;

	int middle = (start + end) / 2;
	if(arr[middle] < num)
		return binary_search_rec(arr, middle + 1, end, num);
	else if(arr[middle] > num)
		return binary_search_rec(arr, start, middle - 1, num);
	else
		return middle;
}


int main()
{
	const int SIZE = 7;
	int s1[] = {1, 3, 5, 6 ,8 ,10, 18};
	int index = binary_search_rec(s1, 0, SIZE - 1, 6);
	std::cout << index << std::endl;
	index = binary_search(s1, SIZE, 5);
	std::cout << index << std::endl;
	return 0;
}
