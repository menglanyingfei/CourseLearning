
// TestDrawLine.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestDrawLineApp: 
// �йش����ʵ�֣������ TestDrawLine.cpp
//

class CTestDrawLineApp : public CWinApp
{
public:
	CTestDrawLineApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestDrawLineApp theApp;