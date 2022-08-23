#include <iostream>

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a,b;
	std::cout<<"Enter A:"<<std::endl;
	std::cin>>a;
	std::cout<<"Enter B:"<<std::endl;
	std::cin>>b;
	swap(a,b);
	std::cout<<"A is: " << a << "\nB is: " << b << std::endl;
	return 0;
}
