#include <stdio.h>
#include "str_len.h"

void main() 
{
	char str1[] = "Hello!";
	int len;

	len = mygetlen(str1);
	printf("str1 len=%d\n", len);	
}
