
// LIXINGYANGView.h : CLIXINGYANGView 类的接口
//

#pragma once


class CLIXINGYANGView : public CScrollView
{
protected: // 仅从序列化创建
	CLIXINGYANGView();
	DECLARE_DYNCREATE(CLIXINGYANGView)

// 特性
public:
	CLIXINGYANGDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CLIXINGYANGView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	// 是否绘制
	BOOL m_bDraw;
	// 绘制形状
	HCURSOR m_hCursor;
	HCURSOR m_hCursorArrow;
	// 鼠标当前位置
	CPoint m_pointCur;
	// 鼠标的前一个位置
	CPoint m_pointOrigin;

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnEditRedo();
	afx_msg void OnUpdateEditRedo(CCmdUI *pCmdUI);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // LIXINGYANGView.cpp 中的调试版本
inline CLIXINGYANGDoc* CLIXINGYANGView::GetDocument() const
   { return reinterpret_cast<CLIXINGYANGDoc*>(m_pDocument); }
#endif

