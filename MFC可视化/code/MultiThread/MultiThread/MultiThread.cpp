#include <Windows.h>
#include <iostream>

int counter = 0;
// 全局函数作为线程函数
DWORD WINAPI Fun1Proc(LPVOID lpParameter);

void main() {
	// 线程句柄
	HANDLE hThread1;

	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	while (++counter <= 100) {
		std::cout << "The main thread is \t running \n";
		Sleep(50); // 让出CPU控制权50ms
	}

	CloseHandle(hThread1);
}
// 合作与竞争
DWORD WINAPI Fun1Proc(LPVOID lpParameter)
{
	while (++counter <= 100) {
		std::cout << "The thread 1 is running \n";
		Sleep(50);
	}

	return 0;
}

