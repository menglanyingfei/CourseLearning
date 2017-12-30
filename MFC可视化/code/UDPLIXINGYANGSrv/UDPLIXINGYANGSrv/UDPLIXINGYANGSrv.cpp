#include <WinSock2.h>
#include <stdio.h>
#include "chess.h"

/*
atoi
一维数组
% /
*/
void main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	int i, j;
	int data[10];
	for (i = 11, j = 1; j<10; i++, j++)
		data[j] = i;
	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
		return;

	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1) {
		WSACleanup();
		return;
	}

	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	char recvBuf[100];
	char sendBuf[100];
	char tempBuf[200];

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	while (1) {
		recvfrom(sockSrv, recvBuf, 100, 0, (SOCKADDR*)&addrClient, &len);
		if ('q' == recvBuf[0]) {
			sendto(sockSrv, "q", strlen("q") + 1, 0, (SOCKADDR*)&addrClient, len);
			printf("Game over!\n");
			break;
		}
		else
		{

			i = atoi(recvBuf);
			data[i] = 1;

			display(data);
			if (judge(data))
			{
				cout << "你输了！" << endl;
				break;
			}
		}
	bb:printf("Please input data:\n");
		gets_s(sendBuf);
		i = atoi(sendBuf);
		if (limit(i, data))
		{
			cout << "禁手！" << endl;
			strcpy(sendBuf, "");
			goto bb;
		}
		data[i] = -1;
		sendto(sockSrv, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&addrClient, len);
		display(data);
		if (judge(data))
		{
			cout << "你赢了！" << endl;
			break;
		}
	}

	closesocket(sockSrv);
	WSACleanup();
	system("pause");
}
