#include <Windows.h>
#include <iostream>

// 函数声明
DWORD WINAPI Fun1Proc(LPVOID lpParameter);
DWORD WINAPI Fun2Proc(LPVOID lpParameter);

int counter = 0;
int tickets = 100;
HANDLE hMutex;

void main() {
	HANDLE hThread1;
	HANDLE hThread2;

	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
	// 互斥信号量
	hMutex = CreateMutex(NULL, FALSE, NULL);
	Sleep(5000);

	CloseHandle(hThread1);
	CloseHandle(hThread2);
}

DWORD WINAPI Fun1Proc(LPVOID lpParameter)
{
	while (TRUE) {
		// 1 -> 0
		WaitForSingleObject(hMutex, INFINITE);

		if (tickets > 0) {
			std::cout << "The thread1 is selling \t a ticket: No." << tickets-- << std::endl;
		}
		else {
			ReleaseMutex(hMutex);
			break;
		}
		// 释放互斥量
		ReleaseMutex(hMutex);
	}
	return 0;
}

DWORD WINAPI Fun2Proc(LPVOID lpParameter)
{
	while (TRUE) {
		WaitForSingleObject(hMutex, INFINITE);

		if (tickets > 0) {
			std::cout << "The thread2 is selling \t a ticket: No. " << tickets-- << std::endl;
		}
		else {
			ReleaseMutex(hMutex);
			break;
		}

		ReleaseMutex(hMutex);
	}
	return 0;
}
