
// MyBackgroundPICView.h : CMyBackgroundPICView ��Ľӿ�
//

#pragma once


class CMyBackgroundPICView : public CView
{
protected: // �������л�����
	CMyBackgroundPICView();
	DECLARE_DYNCREATE(CMyBackgroundPICView)

// ����
public:
	CMyBackgroundPICDoc* GetDocument() const;

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
	virtual ~CMyBackgroundPICView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MyBackgroundPICView.cpp �еĵ��԰汾
inline CMyBackgroundPICDoc* CMyBackgroundPICView::GetDocument() const
   { return reinterpret_cast<CMyBackgroundPICDoc*>(m_pDocument); }
#endif

