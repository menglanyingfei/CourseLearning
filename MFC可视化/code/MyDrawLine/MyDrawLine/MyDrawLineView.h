
// MyDrawLineView.h : CMyDrawLineView 类的接口
//

#pragma once

class CMyDrawLineView : public CView
{
protected: // 仅从序列化创建
	CMyDrawLineView();
	DECLARE_DYNCREATE(CMyDrawLineView)

// 特性
public:
	CMyDrawLineDoc* GetDocument() const;

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

	// 是否绘制
	BOOL m_bDraw;
	// 绘制形状
	HCURSOR m_hCursor;
	// 鼠标当前位置
	CPoint m_pointCur;
	// 鼠标的前一个位置
	CPoint m_pointOrigin;

// 实现
public:
	virtual ~CMyDrawLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEditUndo();
	afx_msg void OnUpdateEditUndo(CCmdUI *pCmdUI);
	afx_msg void OnEditRedo();
	afx_msg void OnUpdateEditRedo(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // MyDrawLineView.cpp 中的调试版本
inline CMyDrawLineDoc* CMyDrawLineView::GetDocument() const
   { return reinterpret_cast<CMyDrawLineDoc*>(m_pDocument); }
#endif

