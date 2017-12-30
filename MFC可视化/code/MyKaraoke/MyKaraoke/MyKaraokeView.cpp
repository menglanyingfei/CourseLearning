
// MyKaraokeView.cpp : CMyKaraokeView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MyKaraoke.h"
#endif

#include "MyKaraokeDoc.h"
#include "MyKaraokeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyKaraokeView

IMPLEMENT_DYNCREATE(CMyKaraokeView, CView)

BEGIN_MESSAGE_MAP(CMyKaraokeView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMyKaraokeView ����/����

CMyKaraokeView::CMyKaraokeView()
{
	// TODO:  �ڴ˴���ӹ������
	m_nWidth = 0;
	m_bTimer = FALSE;

}

CMyKaraokeView::~CMyKaraokeView()
{
}

BOOL CMyKaraokeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMyKaraokeView ����

void CMyKaraokeView::OnDraw(CDC* pDC)
{
	CMyKaraokeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CString str; // L""
	// �汾��ͬ, ����String table
	str.LoadStringW(IDS_NEWSTRING);

	CRect rect;
	rect.top = 100;
	rect.left = 0;

	CSize size = pDC->GetTextExtent(str);
	rect.bottom = rect.top + size.cy;
	rect.right = rect.left + size.cx;

	COLORREF oldColor;
	// �ָ�֮ǰ����ɫ
	oldColor = pDC->SetTextColor(RGB(255, 0, 0));
	pDC->DrawText(str, &rect, DT_LEFT);
	pDC->SetTextColor(oldColor);

	if (m_bTimer) {
		rect.right = rect.left + m_nWidth;
		m_nWidth += 5;
		m_nWidth = m_nWidth > size.cx ? 0 : m_nWidth;
		pDC->DrawText(str, &rect, DT_LEFT);
		m_bTimer = FALSE;

	}
}


// CMyKaraokeView ��ӡ

BOOL CMyKaraokeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMyKaraokeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMyKaraokeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMyKaraokeView ���

#ifdef _DEBUG
void CMyKaraokeView::AssertValid() const
{
	CView::AssertValid();
}

void CMyKaraokeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyKaraokeDoc* CMyKaraokeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyKaraokeDoc)));
	return (CMyKaraokeDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyKaraokeView ��Ϣ�������


int CMyKaraokeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	SetTimer(1, 300, NULL);


	return 0;
}


void CMyKaraokeView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_bTimer = TRUE;
	InvalidateRect(NULL);

	CView::OnTimer(nIDEvent);
}
