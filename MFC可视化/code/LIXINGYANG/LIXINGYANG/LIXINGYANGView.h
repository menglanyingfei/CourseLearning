
// LIXINGYANGView.h : CLIXINGYANGView ��Ľӿ�
//

#pragma once
#include "MySelectColorDlg.h"
#include "MySumDlg.h"

class CLIXINGYANGView : public CView
{
protected: // �������л�����
	CLIXINGYANGView();
	DECLARE_DYNCREATE(CLIXINGYANGView)

// ����
public:
	CLIXINGYANGDoc* GetDocument() const;

// ����
public:
	BOOL m_bRed;
	BOOL m_bGreen;
	BOOL m_bBlue;

	CString m_strName;
	CString m_strGender;
	CString m_strAge;

	BOOL m_bTableTennis;
	BOOL m_bBasketball;
	BOOL m_bSwimming;
	BOOL m_bTennis;

	CString m_strInterest;
	CString m_strJob;
	CString m_strCity;

	CMySelectColorDlg m_dlgSelectColor;
	CMySumDlg m_dlgSum;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CLIXINGYANGView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnColorRed();
	afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
	afx_msg void OnColorGreen();
	afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
	afx_msg void OnColorBlue();
	afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
	afx_msg void OnColorSelectcolor1();
	afx_msg void OnColorSelectcolor2();
	afx_msg void OnSumAddtwonumbers1();
	afx_msg void OnSumAddtwonumbers2();
	afx_msg void OnOperationTestpropertypage();
};

#ifndef _DEBUG  // LIXINGYANGView.cpp �еĵ��԰汾
inline CLIXINGYANGDoc* CLIXINGYANGView::GetDocument() const
   { return reinterpret_cast<CLIXINGYANGDoc*>(m_pDocument); }
#endif

