
// MyDrawLine.h : MyDrawLine Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMyDrawLineApp:
// �йش����ʵ�֣������ MyDrawLine.cpp
//

class CMyDrawLineApp : public CWinApp
{
public:
	CMyDrawLineApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyDrawLineApp theApp;
