
// LIXINGYANG.h : LIXINGYANG Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CLIXINGYANGApp:
// �йش����ʵ�֣������ LIXINGYANG.cpp
//

class CLIXINGYANGApp : public CWinApp
{
public:
	CLIXINGYANGApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLIXINGYANGApp theApp;
