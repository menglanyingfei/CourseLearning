#include <WinSock2.h>
#include <stdio.h>
#include "chess.h"

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

	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	char recvBuf[100];
	char sendBuf[100];
	char tempBuf[200];

	int len = sizeof(SOCKADDR);
	while (1) {
		display(data);

	aa:printf("Please input data(1-9):\n");
		gets_s(sendBuf);
		i = atoi(sendBuf);
		if (limit(i, data))
		{
			strcpy(sendBuf, "");
			goto aa;
		}
		data[i] = 1;
		sendto(sockClient, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&addrSrv, len);
		display(data);
		if (judge(data))
		{
			break;
		}
		recvfrom(sockClient, recvBuf, 100, 0, (SOCKADDR*)&addrSrv, &len);
		if ('q' == recvBuf[0]) {
			sendto(sockClient, "q", strlen("q") + 1, 0, (SOCKADDR*)&addrSrv, len);
			printf("Game over!\n");
			break;
		}
		else
		{
			i = atoi(recvBuf);
			data[i] = -1;
			if (judge(data))
			{
				display(data);
				break;
			}
		}
	}

	closesocket(sockClient);
	WSACleanup();
	system("pause");
}
