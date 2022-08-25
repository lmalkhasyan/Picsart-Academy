#include <iostream>

int main()
{
	for(int i=1, space=2, c=1; i < 8; ++i)
	{
		for(int i = 0; i < space; ++i)
			std::cout<<' ';
		for(int i = 0; i < c; ++i)
			std::cout<<'*';
		std::cout<<std::endl;
		if (space > 0)
			--space;
		if (c < 5)
			c += 2;
	}
    return 0;
}
