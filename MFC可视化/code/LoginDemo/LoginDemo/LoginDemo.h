
// LoginDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLoginDemoApp: 
// �йش����ʵ�֣������ LoginDemo.cpp
//

class CLoginDemoApp : public CWinApp
{
public:
	CLoginDemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLoginDemoApp theApp;