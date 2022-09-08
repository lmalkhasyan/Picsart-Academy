#include <iostream>

char *strcat(char *s1, char *s2)
{
	if(!s1 || !s2)
		return NULL;

	char *temp = s1;
	while(*temp)
		++temp;
	while(*s2)
	{
		*temp = *s2;
		temp++;
		s2++;
	}
	*temp = '\0';
	return s1;
}

int main()
{
	char s1[50] = "HELLO";
	char s2[] = " World";
	std::cout << strcat(s1, s2) << std::endl;
	return 0;
}
