#include <iostream>

int find_min(int num1, int num2)
{
	return num1 <= num2 ? num1 : num2;
}

int main()
{
	int a,b,c,d;
	std::cout << "Enter 4 Nums:\n";
	std::cin >>a>>b>>c>>d;
	if (a+b+c+d == 0)
	{
		std::cout <<"Min Num is: " << find_min(find_min(find_min(a,b),c),d) << std::endl;
	}
	std::cout<<"Sum is not 0" << std::endl;
	return 0;
}
