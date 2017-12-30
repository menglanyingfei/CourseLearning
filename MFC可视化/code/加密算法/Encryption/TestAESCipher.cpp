#include "stdafx.h"
#include "AES.h"
#include<stdlib.h>
#include<string.h>

 char*  getPlainText(char cpuID[])//加密
{

	char result[M * 2+1]; 
	int count = 0;
	unsigned char key[] =
	{
		0x2b, 0x7e, 0x15, 0x16,
		0x28, 0xae, 0xd2, 0xa6,
		0xab, 0xf7, 0x15, 0x88,
		0x09, 0xcf, 0x4f, 0x3c
	};
	AES aes(key);

	int j;
	aes.Cipher((void *)cpuID);
	for (j = 0; j < M; j++)
	{
		int temp  = (unsigned char)cpuID[j];
		Translator10_16(temp, result, count);
	}

	char *Re = (char*)malloc(sizeof(char) *(M * 2 + 1));
	for (int i = 0; i < M * 2; i++)
	{
		Re[i] = result[i];
	}
	Re[M * 2] = '\0';
	return Re;
}

char*   De(char PlainText[])//解密
 {
	char temp[M*2 + 1] = {'\0'};
	for (int i = 0, j = 0; i < M * 2; i += 2, j++)
	{
		temp[j] = (unsigned char)Translator16_10(PlainText, i);
	}

	 unsigned char key[] =
	 {
		 0x2b, 0x7e, 0x15, 0x16,
		 0x28, 0xae, 0xd2, 0xa6,
		 0xab, 0xf7, 0x15, 0x88,
		 0x09, 0xcf, 0x4f, 0x3c
	 };
	 AES aes(key);
	 aes.InvCipher((void *)temp, 21);
	 
	 char *Re = (char*)malloc(sizeof(char) * (M + 1));
	 for (int i = 0; i < M; i++)	 
		 Re[i] = (unsigned char)temp[i];

	 Re[M] = '\0';
	 return Re;
 }

void Translator10_16(int n, char* result, int& index)//十进制转换为十六进制
{
	if (n <= 15)
	{
		result[index++] = '0';
	}
	char a[2] = {'X','X'};
	int i = 1;
	while (n)
	{
		a[i--] = T[n%M];
		n /= M;
	}
	for (i = 0; i < 2; i++)
	{
		if (a[i] != 'X')
		{
			result[index++] = a[i];
		}
	}
	return;
}

int Translator16_10(char* t,int index)//十六进制转换为十进制
{
	int sum = 0;
	int  i = 0;
	while (i++ <= 1)
	{
		sum = sum * 16 + find(t[index++]);
	}
	return sum;
}
int find(char c)
{
	for (int i = 0; i < M; i++)
	{
		if (c == T[i])
			return i;
	}
	return 0;
}


