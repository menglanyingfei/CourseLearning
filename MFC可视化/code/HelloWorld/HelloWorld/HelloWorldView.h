
// HelloWorldView.h : CHelloWorldView ��Ľӿ�
//

#pragma once
#include "DlgSelectColor.h"
#include "DlgAdd2Num.h"

class CHelloWorldView : public CView
{
protected: // �������л�����
	CHelloWorldView();
	DECLARE_DYNCREATE(CHelloWorldView)

// ����
public:
	CHelloWorldDoc* GetDocument() const;

public:
	CDlgSelectColor m_dlgSelectColor;
	CDlgAdd2Num m_dlgAdd2Num;

	BOOL m_bRed;
	BOOL m_bGreen;
	BOOL m_bBlue;

	CString m_strName;
	CString m_strGender;
	CString m_strAge;

// ����
public:

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
	virtual ~CHelloWorldView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
	afx_msg LRESULT OnHide(WPARAM wParam, LPARAM lParam);
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTestmessageSendmessage();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnColorRed();
	afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
	afx_msg void OnColorGreen();
	afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
	afx_msg void OnColorBlue();
	afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
	afx_msg void OnColorSelectcolor();
	afx_msg void OnColorSelectcolorUnModel();
	afx_msg void OnSumAdd2num();
	afx_msg void OnSumAdd2numUnModal();
	afx_msg void OnOperationTestpropertypage();
};

#ifndef _DEBUG  // HelloWorldView.cpp �еĵ��԰汾
inline CHelloWorldDoc* CHelloWorldView::GetDocument() const
   { return reinterpret_cast<CHelloWorldDoc*>(m_pDocument); }
#endif

