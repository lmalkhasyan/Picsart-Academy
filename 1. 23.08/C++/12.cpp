#include <iostream>

int main()
{
	for(int c = 1, space = 5; c < 11; c+=2)
	{
		for(int i = 0; i < space ; ++i)
			std::cout<<' ';
		for(int i = 0; i < c; ++i)
			std::cout<<'*';
		std::cout<<std::endl;
		--space;
	}
	return 0;
}

