
// NetLIXINGYANGChat.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNetLIXINGYANGChatApp: 
// �йش����ʵ�֣������ NetLIXINGYANGChat.cpp
//

class CNetLIXINGYANGChatApp : public CWinApp
{
public:
	CNetLIXINGYANGChatApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNetLIXINGYANGChatApp theApp;