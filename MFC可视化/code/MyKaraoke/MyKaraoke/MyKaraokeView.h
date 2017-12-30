
// MyKaraokeView.h : CMyKaraokeView ��Ľӿ�
//

#pragma once


class CMyKaraokeView : public CView
{
protected: // �������л�����
	CMyKaraokeView();
	DECLARE_DYNCREATE(CMyKaraokeView)

// ����
public:
	CMyKaraokeDoc* GetDocument() const;

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
	virtual ~CMyKaraokeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_nWidth;
	bool m_bTimer;
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MyKaraokeView.cpp �еĵ��԰汾
inline CMyKaraokeDoc* CMyKaraokeView::GetDocument() const
   { return reinterpret_cast<CMyKaraokeDoc*>(m_pDocument); }
#endif

