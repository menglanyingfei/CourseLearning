
// MyKaraoke.h : MyKaraoke Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMyKaraokeApp:
// �йش����ʵ�֣������ MyKaraoke.cpp
//

class CMyKaraokeApp : public CWinApp
{
public:
	CMyKaraokeApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyKaraokeApp theApp;
