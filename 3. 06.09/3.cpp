#include <iostream>

void swap(char& ch1, char& ch2)
{
	char temp = ch1;
	ch1 = ch2;
	ch2 = temp;
}


void reverse_str(char *str)
{
	if(!str || !*str)
		return;

	char *last = str;

	while(*last)
		last++;
	last--;
	while(str != last)
	{
		swap(*str, *last);
		str++;
		last--;
	}
}

int main()
{
	char text[] = "";
	reverse_str(text);
	std::cout << text << std::endl;
	char text2[] = "Hello asd";
	reverse_str(text2);
	std::cout << text2 << std::endl;
	return 0;
}
