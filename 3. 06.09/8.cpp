#include <iostream>

void swap(char *a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

size_t strlen(const char *str)
{
	if(!str)
		return 0;

	size_t len = 0;
	while(str[len])
		++len;
	return len;
}

void move_one(char * str)
{
	if (!str)
		return ;
	size_t i = 1;
	while(str[i])
	{
		swap(str, str+i);
		i++;
	}
}

void strmove(char *str, int n)
{
	if(!str || !(*str) || n < 0)
		return ;

	n = n % strlen(str);
	while(n != 0)
	{
		move_one(str);
		n--;
	}
}

int main()
{
	char s1[] = "Hello";
	strmove(s1, 2);
	std::cout << s1 << std::endl;
	return 0;
}
