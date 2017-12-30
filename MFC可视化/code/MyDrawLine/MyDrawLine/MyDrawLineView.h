
// MyDrawLineView.h : CMyDrawLineView ��Ľӿ�
//

#pragma once

class CMyDrawLineView : public CView
{
protected: // �������л�����
	CMyDrawLineView();
	DECLARE_DYNCREATE(CMyDrawLineView)

// ����
public:
	CMyDrawLineDoc* GetDocument() const;

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

	// �Ƿ����
	BOOL m_bDraw;
	// ������״
	HCURSOR m_hCursor;
	// ��굱ǰλ��
	CPoint m_pointCur;
	// ����ǰһ��λ��
	CPoint m_pointOrigin;

// ʵ��
public:
	virtual ~CMyDrawLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // MyDrawLineView.cpp �еĵ��԰汾
inline CMyDrawLineDoc* CMyDrawLineView::GetDocument() const
   { return reinterpret_cast<CMyDrawLineDoc*>(m_pDocument); }
#endif

