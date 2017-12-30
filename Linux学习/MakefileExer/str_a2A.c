#include "str_A2a.h"
#include "str_len.h"
#include <stdlib.h>

char* str_A2a(char* str)
{
	char* s, ch;
	int len, i;
	len = str_len(str);
	s = (char*)malloc((len+1)*sizeof(char));
	for (i=0; i < len; i++)
	{
		ch=*str;
		if (ch>='A' && ch <= 'Z')
			ch+=32;
		*(s+i) = ch;
		str++;
	}
	*(s+i) = '\0';
	return s;
}

