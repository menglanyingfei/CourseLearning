#include "str_len.h"

int mygetlen(char* str) 
{
	int len=0;
	char ch;
	ch = *str;
	while (ch != '\0')
	{
		len++;
		str++;
		ch=*str;
	}

	return len;
}
