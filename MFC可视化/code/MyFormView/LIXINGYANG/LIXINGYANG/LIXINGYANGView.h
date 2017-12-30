
// LIXINGYANGView.h : CLIXINGYANGView 类的接口
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class CLIXINGYANGView : public CFormView
{
protected: // 仅从序列化创建
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
// 特性
public:
	CLIXINGYANGDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CLIXINGYANGView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // LIXINGYANGView.cpp 中的调试版本
inline CLIXINGYANGDoc* CLIXINGYANGView::GetDocument() const
   { return reinterpret_cast<CLIXINGYANGDoc*>(m_pDocument); }
#endif

