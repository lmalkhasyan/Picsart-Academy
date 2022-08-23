#include <iostream>

int main()
{
	int num1, num2;
	char c;
	std::cout<<"Enter Num 1: " << std::endl;
	std::cin>> num1;
	std::cout<<"Enter Num 2: " << std::endl;
	std::cin>> num2;
	std::cout<<"Enter Operator: "<< std::endl;
	std::cin>> c;
	if (c == '+')
		std::cout<<num1+num2 << std::endl;
	else if (c == '-')
		std::cout<<num1-num2 << std::endl;
	else if (c == '*')
		std::cout<<num1*num2 << std::endl;
	else if (c == '/')
		std::cout<<num1/num2 << std::endl;
	else if (c == '%')
		std::cout<<num1%num2 << std::endl;
	return 0;
}
