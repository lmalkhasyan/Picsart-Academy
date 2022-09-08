#include <iostream>
#include <map>

int my_add(int num1, int num2)
{
	return num1 + num2;
}

int my_sub(int num1, int num2)
{
	return num1 - num2;
}

int my_mul(int num1, int num2)
{
	return num1 * num2;
}

int my_div(int num1, int num2)
{
	if(num2 == 0)
	{
		std::cout << "Division by Zero!" << std::endl;
		return (-1);
	}
	return num1 / num2;
}

int calculator(int num1, int num2, char op)
{
	typedef int (*operation)(int, int);
	int result = 0;
	std::map<char, operation>my_map{{'+', my_add},
			{'-', my_sub},{'*', my_mul},{'/', my_div} };

	auto it = my_map.find(op);
	if (it != my_map.end())
        result = it->second(num1, num2);
    else 
        std::cout << "Operation not found" << std::endl;
	return result;
}
int main()
{
	int num1, num2;
	char op;
	std::cout << "Enter First Number:" << std::endl;
	std::cin >> num1;
	std::cout << "Enter Operation(+, -, *, /):" << std::endl;
	std::cin >> op;
	std::cout << "Enter Second Number:" << std::endl;
	std::cin >> num2;
	std::cout << "Result is: " << calculator(num1, num2, op) << std::endl;
	return 0;
}
