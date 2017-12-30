#include"Time.h"
#include<string.h>

char* getTime()
{
	char *Time = (char*)malloc(sizeof(char)*9);

	time_t t;
	struct tm* lt;
	time(&t);
	int n=0;
	lt=localtime(&t);
	//printf("%d/%d/%d %d:%d:%d\n",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min,lt->tm_sec);
	//printf("%d %d %d\n",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday);
	
	char str[5] = {'x','x','x','x','x'};
	int i=0;
	itoa(lt->tm_year+1900, str, 10); //这句需要头文件#include <ctype.h>
	for (;i<4;i++)
	{
		Time[i] = str[i];
	}


	if (lt->tm_mon+1 <=9)
	{
		Time[i++] = '0';
		itoa(lt->tm_mon+1,str,10);
		Time[i++] = str[0];
	}
	else
	{
		itoa(lt->tm_mon+1,str,10);
		Time[i++] = str[0];
		Time[i++] = str[1];
	}
	 
	if (lt->tm_mday <=9)
	{
		Time[i++] = '0';
		itoa(lt->tm_mday,str,10);
		Time[i++] = str[0];
	}
	else
	{
		itoa(lt->tm_mday,str,10);
		Time[i++] = str[0];
		Time[i++] = str[1];
	}

	Time[8] = '\0';
	return Time;
}
