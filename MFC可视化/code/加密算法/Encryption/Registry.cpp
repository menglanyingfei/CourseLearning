#include"Registry.h"


int Write_reg_ID(char input[])
{
	char updated[64];
	HKEY hKey;


	for (int i = 0,j = 0; i < 32; i++)
	{
		updated[j++] = input[i];
		updated[j++] = '\0';
	}

	if (RegCreateKey(HKEY_USERS, (LPCSTR)".DEFAULT\\System", &hKey) != ERROR_SUCCESS)
	{
		printf("Error #RegCreateKey !!!\n");
		return -1;
	}

	if (RegSetValueEx(hKey,(LPCSTR)"I\0D\0", 0, REG_SZ, (const BYTE *)updated, sizeof(updated)) != ERROR_SUCCESS)
	{
		printf("Error #RegSetValueEx !!!\n");
		return -1;
	}

	RegCloseKey(hKey);

	//printf("Successful\n");
	return 0;
}


char* Read_reg_ID()
{
	HKEY hKEY;

	char *result = (char*)malloc(sizeof(char)*33);

	DWORD dataType;
	DWORD dataSize;

	char data[200] = { 0 };

	if (RegOpenKeyEx(HKEY_USERS, (LPCSTR)".DEFAULT\\System", NULL, KEY_READ, &hKEY) != ERROR_SUCCESS)        //如果无法打开hKEY,则中止程序的执行
	{
		printf("Error #RegOpenKeyEx !!!\n");
		return NULL;
	}


	if (RegQueryValueEx(hKEY, (LPCSTR)"I\0D\0", NULL, &dataType, (LPBYTE)data, &dataSize) != ERROR_SUCCESS)       //如果无法打开hKEY,则中止程序的执行
	{
		printf("Error #RegQueryValueEx !!!\n");
		return NULL;
	}

	/*printf("Data Type:%d\n", dataType);
	printf("Data Size:%d\n", dataSize);
	printf("data: ");*/

	for (unsigned i = 0, j = 0; i < dataSize; i += 2, j++)
	{
		//printf("%c", data[i]);
		result[j] = data[i];
	}
	result[32] = '\0';
	//printf("\n");

	RegCloseKey(hKEY); 

	return result;
}
// E367810DB9DDC8F29FAA8DC8A42CC73E
// E367810DB9DDC8F29FAA8DC8A42CC73E


