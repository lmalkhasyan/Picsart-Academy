#include <iostream>

size_t strlen(const char *str)
{
	if(!str)
		return 0;

	size_t len = 0;
	while(str[len])
		++len;
	return len;
}

int main()
{
	const char *text = "HELLO";
	std::cout << strlen(text) << std::endl;
	return 0;
}
