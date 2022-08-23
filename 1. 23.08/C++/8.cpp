#include <iostream>

void putnumber(int num)
{
	if (!num)
		return;
	putnumber(num/10);	
	std::cout<<(num % 10)<<std::endl;
}
int main()
{
	int num;
	std::cin>>num;
	putnumber(num);
	return 0;
}

