
// LIXINGYANGView.h : CLIXINGYANGView ��Ľӿ�
//

#pragma once


class CLIXINGYANGView : public CScrollView
{
protected: // �������л�����
	CLIXINGYANGView();
	DECLARE_DYNCREATE(CLIXINGYANGView)

// ����
public:
	CLIXINGYANGDoc* GetDocument() const;

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
	virtual ~CLIXINGYANGView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	// �Ƿ����
	BOOL m_bDraw;
	// ������״
	HCURSOR m_hCursor;
	HCURSOR m_hCursorArrow;
	// ��굱ǰλ��
	CPoint m_pointCur;
	// ����ǰһ��λ��
	CPoint m_pointOrigin;

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // LIXINGYANGView.cpp �еĵ��԰汾
inline CLIXINGYANGDoc* CLIXINGYANGView::GetDocument() const
   { return reinterpret_cast<CLIXINGYANGDoc*>(m_pDocument); }
#endif

