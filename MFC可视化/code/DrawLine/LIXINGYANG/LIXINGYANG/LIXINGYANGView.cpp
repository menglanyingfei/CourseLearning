
// LIXINGYANGView.cpp : CLIXINGYANGView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "LIXINGYANG.h"
#endif

#include "LIXINGYANGDoc.h"
#include "LIXINGYANGView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLIXINGYANGView

IMPLEMENT_DYNCREATE(CLIXINGYANGView, CScrollView)

BEGIN_MESSAGE_MAP(CLIXINGYANGView, CScrollView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_EDIT_REDO, &CLIXINGYANGView::OnEditRedo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, &CLIXINGYANGView::OnUpdateEditRedo)
	ON_COMMAND(ID_EDIT_UNDO, &CLIXINGYANGView::OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, &CLIXINGYANGView::OnUpdateEditUndo)
END_MESSAGE_MAP()

// CLIXINGYANGView ����/����

CLIXINGYANGView::CLIXINGYANGView()
{
	// TODO: �ڴ˴���ӹ������
	m_bDraw = FALSE;
	// �����׼�����
	m_hCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);

	m_hCursorArrow = AfxGetApp()->LoadStandardCursor(IDC_ARROW);

}

CLIXINGYANGView::~CLIXINGYANGView()
{
}

BOOL CLIXINGYANGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	// �޸�ȱʡ�Ĵ�����, �������, ˮƽ�仯
	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW, m_hCursorArrow,
		(HBRUSH)::GetStockObject(BLACK_BRUSH));

	return CScrollView::PreCreateWindow(cs);
}

// CLIXINGYANGView ����

void CLIXINGYANGView::OnDraw(CDC* pDC)
{
	CLIXINGYANGDoc* pDoc = GetDocument();
	// �����ĵ�-��ͼ�ṹ, ���� -> �ĵ�; �����ݵĲ����Լ���ʾ -> ��ͼ
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->SetROP2(R2_WHITE);
	pDoc->OnDraw(pDC);

	// ����һ������
	CPen pen(PS_SOLID, 5, RGB(255, 255, 0));
	// ���»���ѡ���豸������
	CPen* pOldPen = pDC->SelectObject(&pen);
	// ʹ���»��ʻ�ͼ
	pDC->SetROP2(R2_COPYPEN);
	// ��ȡScrollҳ��Ĵ�С(�߼���С)
	CSize size = GetTotalSize();

	// ���Ʊ߽���
	pDC->MoveTo(size.cx, 0);
	pDC->LineTo(size.cx, size.cy);
	pDC->LineTo(0, size.cy);
	// ��ԭ�ɻ���
	pDC->SelectObject(pOldPen);

}


// CLIXINGYANGView ��ӡ

BOOL CLIXINGYANGView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	
	return DoPreparePrinting(pInfo);
}

void CLIXINGYANGView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CLIXINGYANGView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CLIXINGYANGView ���

#ifdef _DEBUG
void CLIXINGYANGView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CLIXINGYANGView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CLIXINGYANGDoc* CLIXINGYANGView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLIXINGYANGDoc)));
	return (CLIXINGYANGDoc*)m_pDocument;
}
#endif //_DEBUG


// CLIXINGYANGView ��Ϣ�������


void CLIXINGYANGView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this); // ��ȡ��ǰ�豸������
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);

	CSize sizeScroll = GetTotalSize();
	CRect rectScroll(0, 0, sizeScroll.cx, sizeScroll.cy);
	if (!rectScroll.PtInRect(point))
		::SetCursor(m_hCursorArrow);
	else
		::SetCursor(m_hCursor);

	if (m_bDraw) {
		

		dc.SetROP2(R2_NOT); // ���û���ģʽΪ"����ȡ��"

		CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)); //�豸������ĵ�ǰ��ˢ���豸����������Ӧ�ó���������豸֮����н�����
		CBrush *OldBrush = dc.SelectObject(pBrush);
		//dc.MoveTo(m_pointOrigin); // �����߶�1(Ĩ��ԭ�����߶�)
		//dc.LineTo(m_pointCur);

		//dc.MoveTo(m_pointOrigin); // �����߶�2(�����µ��߶�)
		//dc.LineTo(point);

		dc.Rectangle(CRect(m_pointOrigin, m_pointCur));
		dc.Rectangle(CRect(m_pointOrigin, point));

		m_pointCur = point; // ���浱ǰ���λ��
		OldBrush = pBrush;
	}
	CScrollView::OnMouseMove(nFlags, point);
}


void CLIXINGYANGView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// �ͻ����豸������
	CClientDC dc(this);
	// ׼���豸������
	OnPrepareDC(&dc);
	// �豸���굽�߼�����
	dc.DPtoLP(&point);

	CSize size = GetTotalSize(); // ��ȡScrollҳ���С
	CRect rectScroll(0, 0, size.cx, size.cy); // Scrollҳ��Rect
	if (!rectScroll.PtInRect(point)) // ��������Ƿ���Scrollҳ������
		return;

	m_pointOrigin = point;
	m_pointCur = m_pointOrigin; // �������λ����Ϣ

	SetCapture(); // �������
	m_bDraw = TRUE; // ����ʼ����

	RECT rect;
	GetClientRect(&rect); // ��ȡ�ͻ�������

	dc.LPtoDP(&rectScroll); // ��Scrollҳ������ת�����豸����

	CRect resultRect;
	resultRect.IntersectRect(&rect, &rectScroll); // �������������ص�����

	ClientToScreen(&resultRect); // ���ͻ����߼�����ת������Ļ����

	ClipCursor(&resultRect); // �������Χ�޶��ڸ�����

	CScrollView::OnLButtonDown(nFlags, point);
}


void CLIXINGYANGView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (m_bDraw) {
		m_bDraw = FALSE; // ���ƽ���
		ReleaseCapture(); // �ͷ�"��겶��"
		ClipCursor(NULL); // ȡ��"�޶����"
		// View���л�ȡDocָ�� ����߶�
		CLIXINGYANGDoc* pDoc = GetDocument();

		CClientDC dc(this);
		OnPrepareDC(&dc);

		dc.DPtoLP(&point);

		// ���޸�!
		//pDoc->AddLine(m_pointOrigin, point);		
		//pDoc->AddView();

		pDoc->AddLine(m_pointOrigin, point);
		
		pDoc->ClearArray2Lines();
	}

	CScrollView::OnLButtonUp(nFlags, point);
}


void CLIXINGYANGView::OnEditRedo()
{
	// TODO:  �ڴ���������������
	CLIXINGYANGDoc* pDoc = GetDocument();
	pDoc->OnRedo();
}


void CLIXINGYANGView::OnUpdateEditRedo(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	CLIXINGYANGDoc* pDoc = GetDocument();
	pCmdUI->Enable(pDoc->GetArray2LinesSize());
}


void CLIXINGYANGView::OnEditUndo()
{
	// TODO:  �ڴ���������������
	CLIXINGYANGDoc* pDoc = GetDocument();
	// ����ͼ���л�ȡ�ĵ������ĺ���
	pDoc->OnUndo();
}


void CLIXINGYANGView::OnUpdateEditUndo(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	CLIXINGYANGDoc* pDoc = GetDocument();

	pCmdUI->Enable(pDoc->GetArrayLinesSize());

}


void CLIXINGYANGView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	// Scrollҳ���С
	CSize size;
	size.cx = 640;
	size.cy = 480;
	SetScrollSizes(MM_TEXT, size);

}