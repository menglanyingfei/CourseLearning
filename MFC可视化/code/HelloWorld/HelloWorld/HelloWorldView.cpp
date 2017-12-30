
// HelloWorldView.cpp : CHelloWorldView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "HelloWorld.h"
#endif

#include "HelloWorldDoc.h"
#include "HelloWorldView.h"

#include "PageSelectColor.h"
#include "PageAdd2Num.h"
#include "PagePersonal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloWorldView

IMPLEMENT_DYNCREATE(CHelloWorldView, CView)

BEGIN_MESSAGE_MAP(CHelloWorldView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TESTMESSAGE_SENDMESSAGE, &CHelloWorldView::OnTestmessageSendmessage)

	ON_MESSAGE(WM_HIDE, OnHide)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_COLOR_RED, &CHelloWorldView::OnColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CHelloWorldView::OnUpdateColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CHelloWorldView::OnColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CHelloWorldView::OnUpdateColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CHelloWorldView::OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CHelloWorldView::OnUpdateColorBlue)
	ON_COMMAND(ID_COLOR_SELECTCOLOR, &CHelloWorldView::OnColorSelectcolor)
	ON_COMMAND(ID_COLOR_SELECTCOLOR32777, &CHelloWorldView::OnColorSelectcolorUnModel)
	ON_COMMAND(ID_SUM_ADD2NUM, &CHelloWorldView::OnSumAdd2num)
	ON_COMMAND(ID_SUM_ADD2NUM32779, &CHelloWorldView::OnSumAdd2numUnModal)
	ON_COMMAND(ID_OPERATION_TESTPROPERTYPAGE, &CHelloWorldView::OnOperationTestpropertypage)
END_MESSAGE_MAP()

// CHelloWorldView ����/����

CHelloWorldView::CHelloWorldView()
{
	// TODO:  �ڴ˴���ӹ������, ��ʼ��
	m_bRed = FALSE;
	m_bGreen = FALSE;
	m_bBlue = FALSE;

	m_strName = L"��";
	m_strGender = L"��";
	m_strAge = L"20";
}

CHelloWorldView::~CHelloWorldView()
{
}

BOOL CHelloWorldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CHelloWorldView ����
// ������ʾ
void CHelloWorldView::OnDraw(CDC* pDC)
{
	// ��ȡ����ͼ���Ӧ���ĵ���Ķ���
	CHelloWorldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	COLORREF color = RGB(
		m_bRed ? 255 : 0,
		m_bGreen ? 255 : 0,
		m_bBlue ? 255 : 0);
	pDC->SetTextColor(color);
	// ���Hello World
	pDC->TextOut(0, 0, L"Hello World"); // _T("HelloWorld")

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);

	pDC->TextOut(0, 1 * tm.tmHeight, L"����: " + m_strName);
	pDC->TextOut(0, 2 * tm.tmHeight, L"�Ա�: " + m_strGender);
	pDC->TextOut(0, 3 * tm.tmHeight, L"����: " + m_strAge);
	
}

LRESULT CHelloWorldView::OnHide(WPARAM wParam, LPARAM lParam) {
	MessageBox(L"Hide");

	return 0;
}

// CHelloWorldView ��ӡ

BOOL CHelloWorldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CHelloWorldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CHelloWorldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CHelloWorldView ���

#ifdef _DEBUG
void CHelloWorldView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloWorldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloWorldDoc* CHelloWorldView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloWorldDoc)));
	return (CHelloWorldDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloWorldView ��Ϣ�������


void CHelloWorldView::OnTestmessageSendmessage()
{
	// TODO:  �ڴ���������������
	PostMessage(WM_HIDE, 0, 0);
}


void CHelloWorldView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	CStatusBar* pStatus;
	// ����C printf()
	str.Format(L"X=%d, Y=%d", point.x, point.y);
	// Ӧ�ó������, ����ܶ���, ��ȡ����ܴ����µ�ĳ��С���ڶ���
	pStatus = (CStatusBar*)(AfxGetApp()->m_pMainWnd->
		GetDescendantWindow(AFX_IDW_STATUS_BAR));
	// ״̬�����ڶ���
	pStatus->SetPaneText(1, str);

	CView::OnMouseMove(nFlags, point);
}


void CHelloWorldView::OnColorRed()
{
	// TODO:  �ڴ���������������
	m_bRed = !m_bRed;
	// ˢ�´���
	Invalidate();
}


void CHelloWorldView::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_bRed);
}


void CHelloWorldView::OnColorGreen()
{
	// TODO:  �ڴ���������������
	m_bGreen = !m_bGreen;
	// ˢ�´���
	Invalidate();
}


void CHelloWorldView::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_bGreen);
}


void CHelloWorldView::OnColorBlue()
{
	// TODO:  �ڴ���������������
	m_bBlue = !m_bBlue;
	// ˢ�´���
	Invalidate();
}


void CHelloWorldView::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_bBlue);
}


void CHelloWorldView::OnColorSelectcolor()
{
	// TODO:  �ڴ���������������
	CDlgSelectColor dlgSelectColor;
	// ģʽ�Ի���
	if (dlgSelectColor.DoModal() == IDOK) {
		this->m_bRed = dlgSelectColor.m_bRed;
		this->m_bGreen = dlgSelectColor.m_bGreen;
		this->m_bBlue = dlgSelectColor.m_bBlue;

		// ����ˢ��
		Invalidate();
	}
}


void CHelloWorldView::OnColorSelectcolorUnModel()
{
	// TODO:  �ڴ���������������
	// ��ģʽ�Ի���
	if (!m_dlgSelectColor.m_hWnd)
		m_dlgSelectColor.Create(IDD_DIALOG_SELECTCOLOR);

	m_dlgSelectColor.ShowWindow(SW_SHOW);
}


void CHelloWorldView::OnSumAdd2num()
{
	// TODO:  �ڴ���������������
	CDlgAdd2Num dlgAdd2Num;

	dlgAdd2Num.DoModal();
}


void CHelloWorldView::OnSumAdd2numUnModal()
{
	// TODO:  �ڴ���������������
	if (!m_dlgAdd2Num.m_hWnd)
		m_dlgAdd2Num.Create(IDD_DIALOG_ADD2NUM);

	m_dlgAdd2Num.ShowWindow(SW_SHOW);


}


void CHelloWorldView::OnOperationTestpropertypage()
{
	// TODO:  �ڴ���������������
	CPropertySheet sheet;
	CPageSelectColor pageSelectColor;
	CPageAdd2Num pageAdd2Num;
	CPagePersonal pagePersonal;

	// �������ҳ
	sheet.AddPage(&pageSelectColor);
	sheet.AddPage(&pageAdd2Num);
	sheet.AddPage(&pagePersonal);

	// ���ԶԻ���
	if (sheet.DoModal() == IDOK) {
		this->m_bRed = pageSelectColor.m_bRed;
		this->m_bGreen = pageSelectColor.m_bGreen;
		this->m_bBlue = pageSelectColor.m_bBlue;

		this->m_strName = pagePersonal.m_strName;
		this->m_strGender = pagePersonal.m_strGender;
		this->m_strAge = pagePersonal.m_strAge;

		Invalidate();
	}
}










