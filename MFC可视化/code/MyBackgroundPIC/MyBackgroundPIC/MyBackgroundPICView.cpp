
// MyBackgroundPICView.cpp : CMyBackgroundPICView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MyBackgroundPIC.h"
#endif

#include "MyBackgroundPICDoc.h"
#include "MyBackgroundPICView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyBackgroundPICView

IMPLEMENT_DYNCREATE(CMyBackgroundPICView, CView)

BEGIN_MESSAGE_MAP(CMyBackgroundPICView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMyBackgroundPICView ����/����

CMyBackgroundPICView::CMyBackgroundPICView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMyBackgroundPICView::~CMyBackgroundPICView()
{
}

BOOL CMyBackgroundPICView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMyBackgroundPICView ����

void CMyBackgroundPICView::OnDraw(CDC* pDC)
{
	CMyBackgroundPICDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CBitmap bitmap;

	bitmap.LoadBitmapW(IDB_BITMAP1);

	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);
	dcCompatible.SelectObject(&bitmap);
	CRect rect;
	GetClientRect(&rect);
	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);

	BITMAP bmInfo;
	bitmap.GetBitmap(&bmInfo);
	// ȫ������ʾͼƬ
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, bmInfo.bmWidth,
		bmInfo.bmHeight, SRCCOPY);
}


// CMyBackgroundPICView ��ӡ

BOOL CMyBackgroundPICView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMyBackgroundPICView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMyBackgroundPICView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMyBackgroundPICView ���

#ifdef _DEBUG
void CMyBackgroundPICView::AssertValid() const
{
	CView::AssertValid();
}

void CMyBackgroundPICView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyBackgroundPICDoc* CMyBackgroundPICView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyBackgroundPICDoc)));
	return (CMyBackgroundPICDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyBackgroundPICView ��Ϣ�������
