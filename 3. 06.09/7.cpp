#include <iostream>

void strset(char *str, char ch)
{
	if(!str)
		return ;
	
	while(*str)
		*str++ = ch;
}

int main()
{
	char s1[] = "World";
	strset(s1, 'B');
	std::cout << s1 << std::endl;
	return 0;
}
