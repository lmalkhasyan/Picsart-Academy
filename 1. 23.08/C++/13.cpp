#include <iostream>

int Mult(int num1, int num2, int num3)
{
	return num1 * num2 * num3;
}

int main()
{
	int num1, num2, num3;
	std::cout<<"Enter Num1:"<<std::endl;
	std::cin >> num1;
	std::cout<<"Enter Num2:"<<std::endl;
	std::cin >> num2;	
	std::cout<<"Enter Num3:"<<std::endl;
	std::cin >> num3;
	std::cout<<"Num1 * Num2 * Num3 = "<<Mult(num1,num2,num3)<<std::endl;
}
	
