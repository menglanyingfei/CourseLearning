#include <Windows.h>
#include <iostream>

int counter = 0;
// ȫ�ֺ�����Ϊ�̺߳���
DWORD WINAPI Fun1Proc(LPVOID lpParameter);

void main() {
	// �߳̾��
	HANDLE hThread1;

	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	while (++counter <= 100) {
		std::cout << "The main thread is \t running \n";
		Sleep(50); // �ó�CPU����Ȩ50ms
	}

	CloseHandle(hThread1);
}
// �����뾺��
DWORD WINAPI Fun1Proc(LPVOID lpParameter)
{
	while (++counter <= 100) {
		std::cout << "The thread 1 is running \n";
		Sleep(50);
	}

	return 0;
}

