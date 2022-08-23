#include <iostream>

int find_max(int num1, int num2, int num3)
{
	if(num1 >= num2 && num1 >= num3)
		return(num1);
	else if(num2 >= num1 && num2 >= num3)
		return(num2);
	else
		return(num3);
}


int find_min(int num1, int num2, int num3)
{
	if(num1 <= num2 && num1 <= num3)
		return(num1);
	else if(num2 <= num1 && num2 <= num3)
		return(num2);
	else
		return(num3);
}

int main()
{
	int x, y, z;
	std::cout << "Enter three Numbers:"<< std::endl;
	std::cin >> x >> y >> z;
	int max = find_max(x,y,z);
	std::cout << "Max Num is:" << max << std::endl;
	int min = find_min(x,y,z);
	std::cout << "Min Num is:" << min << std::endl;
	return (0);
}
