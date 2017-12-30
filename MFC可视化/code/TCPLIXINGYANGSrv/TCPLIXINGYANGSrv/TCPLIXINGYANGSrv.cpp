#include <WinSock2.h>
#include <stdio.h>
#include <string>
#include <fstream>  
#include <iostream>

using namespace std;

string readFile() {
	ifstream myfile("file.txt");
	string temp, data;
	if (!myfile.is_open())  
    {  
        cout << "未成功打开文件" << endl;  
    } 
	while(getline(myfile,temp))  
    {  
         data += temp + "\n"; 
	}
    myfile.close(); 
	
	return data;
}

void main()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(1,1);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
		return;

	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1) {
		WSACleanup();
		return;
	}

	SOCKET sockSrv = socket(AF_INET,SOCK_STREAM,0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
	addrSrv.sin_family=AF_INET;
	addrSrv.sin_port=htons(6000);

	bind(sockSrv,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	listen(sockSrv,5);

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

	while(1) {
		SOCKET sockConn = accept(sockSrv,(SOCKADDR*)&addrClient,&len);
		//char sendBuf[100];
		char sendBuf[1024];

		string str = readFile();
		const char* charstr = str.c_str();
		sprintf_s(sendBuf, charstr,inet_ntoa(addrClient.sin_addr));

		send(sockConn,sendBuf,strlen(sendBuf)+1,0);
		char recvBuf[100];
		recv(sockConn,recvBuf,100,0);
		printf("%s\n",recvBuf);

		closesocket(sockConn);

		printf("Input \'x' for exit, or continue.\n");
		if (getchar()=='x')
			break;
	}
	closesocket(sockSrv);
	WSACleanup();
}


