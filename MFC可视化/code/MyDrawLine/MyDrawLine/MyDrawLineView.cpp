
// MyDrawLineView.cpp : CMyDrawLineView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MyDrawLine.h"
#endif

#include "MyDrawLineDoc.h"
#include "MyDrawLineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyDrawLineView

IMPLEMENT_DYNCREATE(CMyDrawLineView, CView)

BEGIN_MESSAGE_MAP(CMyDrawLineView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_EDIT_UNDO, &CMyDrawLineView::OnEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, &CMyDrawLineView::OnUpdateEditUndo)
	ON_COMMAND(ID_EDIT_REDO, &CMyDrawLineView::OnEditRedo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, &CMyDrawLineView::OnUpdateEditRedo)
END_MESSAGE_MAP()

// CMyDrawLineView ����/����

CMyDrawLineView::CMyDrawLineView()
{
	// TODO: �ڴ˴���ӹ������
	m_bDraw = FALSE;
	m_hCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);//��ʼ��m_hCursorΪʮ�ֹ��
}

CMyDrawLineView::~CMyDrawLineView()
{
}

BOOL CMyDrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW,
										m_hCursor,
										(HBRUSH)::GetStockObject(BLACK_BRUSH));

	return CView::PreCreateWindow(cs);
}

// CMyDrawLineView ����
void CMyDrawLineView::OnDraw(CDC *pDC)
{
	CMyDrawLineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	pDC->SetROP2(R2_WHITE);
	pDoc->OnDraw(pDC);
	
}


// CMyDrawLineView ��ӡ
BOOL CMyDrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMyDrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMyDrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMyDrawLineView ���

#ifdef _DEBUG
void CMyDrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CMyDrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDrawLineDoc* CMyDrawLineView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDrawLineDoc)));
	return (CMyDrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyDrawLineView ��Ϣ�������
// ��ס�������ƶ�
void CMyDrawLineView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_bDraw) {
		CClientDC dc(this);//�����ϲ�������������׼���˻��������ʣ����� �����Ļ�������ˣ���Ϳ��Ի����ˡ� ��������Ļ���������DC�� 
		dc.SetROP2(R2_NOT);
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//�豸������ĵ�ǰ��ˢ���豸����������Ӧ�ó���������豸֮����н�����
		CBrush *OldBrush=dc.SelectObject(pBrush);
		
		dc.MoveTo(m_pointOrigin);
		//����
		dc.Rectangle(CRect(m_pointOrigin,m_pointCur));
		dc.MoveTo(m_pointOrigin);
		//����
		dc.Rectangle(CRect(m_pointOrigin,point));
		m_pointCur = point;
		OldBrush=pBrush;
		
	}
	// ���ֻҪ�ƶ��͵���
	CView::OnMouseMove(nFlags, point);
}

// ̧��������
void CMyDrawLineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_bDraw) {
		m_bDraw = FALSE;
		ReleaseCapture();
		ClipCursor(NULL);//�ͷ����ʹ��Ȩ�ޣ���������ȫ���ƶ���

		CMyDrawLineDoc* pDoc = GetDocument();
		pDoc->AddLine(m_pointOrigin,point);
		pDoc->ClearArray2Lines();
	}

	CView::OnLButtonUp(nFlags, point);
}

// ��ס������
void CMyDrawLineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_pointOrigin = point;
	m_pointCur = point;

	SetCapture();
	m_bDraw = TRUE;
	//�����������
	RECT rect;
	GetClientRect(&rect);//ȡ������rect
	ClientToScreen(&rect);
	ClipCursor(&rect);

	CView::OnLButtonDown(nFlags, point);
}



void CMyDrawLineView::OnEditUndo()
{
	// TODO: �ڴ���������������
	CMyDrawLineDoc* pDoc = GetDocument();
	pDoc->OnUndo();
}


void CMyDrawLineView::OnUpdateEditUndo(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	CMyDrawLineDoc* pDoc = GetDocument();
	pCmdUI->Enable(pDoc->GetArrayLinesSize());
}


void CMyDrawLineView::OnEditRedo()
{
	// TODO: �ڴ���������������
	CMyDrawLineDoc* pDoc = GetDocument();
	pDoc->OnRedo();
}


void CMyDrawLineView::OnUpdateEditRedo(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	CMyDrawLineDoc* pDoc = GetDocument();
	pCmdUI->Enable(pDoc->GetArray2LinesSize());
}
