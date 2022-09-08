#include <iostream>

char *to_upper_case(char *str)
{
	if(!str)
		return NULL;
	char *tmp = str;

	while(*str)
	{
		if(*str >= 'a' && *str <= 'z')
			*str = *str - 32;
		str++;
	}
	return tmp;
}

int main()
{
	char text[] = "asdkoadoka   +34234";
	std::cout << to_upper_case(text) << std::endl;
	return 0;
}
