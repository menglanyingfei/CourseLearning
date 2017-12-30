
// LIXINGYANGView.h : CLIXINGYANGView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CLIXINGYANGView : public CFormView
{
protected: // �������л�����
	CLIXINGYANGView();
	DECLARE_DYNCREATE(CLIXINGYANGView)

public:
	enum{ IDD = IDD_LIXINGYANG_FORM };

	enum enumIntensity {
		INTENSITY_LIGHT,
		INTENSITY_DARK
	};
	enumIntensity m_enumIntensity;
	CRect m_rectSample;
// ����
public:
	CLIXINGYANGDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

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
	BOOL m_bBlue;
	BOOL m_bGreen;
	BOOL m_bRed;
	CStatic m_ctrlSample;
	afx_msg void OnColorDarkcolor();
	afx_msg void OnUpdateColorDarkcolor(CCmdUI *pCmdUI);
	afx_msg void OnColorLightcolor();
	afx_msg void OnUpdateColorLightcolor(CCmdUI *pCmdUI);
	afx_msg void OnClickedCheckBlue();
	afx_msg void OnClickedCheckGreen();
	afx_msg void OnClickedCheckRed();
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // LIXINGYANGView.cpp �еĵ��԰汾
inline CLIXINGYANGDoc* CLIXINGYANGView::GetDocument() const
   { return reinterpret_cast<CLIXINGYANGDoc*>(m_pDocument); }
#endif

