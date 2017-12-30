#include <stdio.h>
#include "str_len.h"
#include "str_a2A.h"
#include "str_A2a.h"

void main() 
{
	char str1[] = "Hello World!";
	int len;

	char* str2, *str3;
	len = str_len(str1);
	printf("str1 len=%d\n", len);
	str2=str_a2A(str1);
	str3=str_A2a(str1);
	printf("%s ", str1);
	printf("%s ", str2);
	printf("%s ", str3);
}
