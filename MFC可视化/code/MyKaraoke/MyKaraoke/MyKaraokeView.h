
// MyKaraokeView.h : CMyKaraokeView 类的接口
//

#pragma once


class CMyKaraokeView : public CView
{
protected: // 仅从序列化创建
	CMyKaraokeView();
	DECLARE_DYNCREATE(CMyKaraokeView)

// 特性
public:
	CMyKaraokeDoc* GetDocument() const;

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
	virtual ~CMyKaraokeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_nWidth;
	bool m_bTimer;
// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MyKaraokeView.cpp 中的调试版本
inline CMyKaraokeDoc* CMyKaraokeView::GetDocument() const
   { return reinterpret_cast<CMyKaraokeDoc*>(m_pDocument); }
#endif

