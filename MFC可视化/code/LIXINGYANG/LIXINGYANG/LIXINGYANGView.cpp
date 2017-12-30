
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

#include "PageSelectColor.h"
#include "PageAdd2Num.h"
#include "PagePersonal.h"
#include "InterestPage.h"
#include "JobPage.h"
#include "PageCtlColor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLIXINGYANGView

IMPLEMENT_DYNCREATE(CLIXINGYANGView, CView)

BEGIN_MESSAGE_MAP(CLIXINGYANGView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_COLOR_RED, &CLIXINGYANGView::OnColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CLIXINGYANGView::OnUpdateColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CLIXINGYANGView::OnColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CLIXINGYANGView::OnUpdateColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CLIXINGYANGView::OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CLIXINGYANGView::OnUpdateColorBlue)
	ON_COMMAND(ID_COLOR_SELECTCOLOR1, &CLIXINGYANGView::OnColorSelectcolor1)
	ON_COMMAND(ID_COLOR_SELECTCOLOR2, &CLIXINGYANGView::OnColorSelectcolor2)
	ON_COMMAND(ID_SUM_ADDTWONUMBERS1, &CLIXINGYANGView::OnSumAddtwonumbers1)
	ON_COMMAND(ID_SUM_ADDTWONUMBERS2, &CLIXINGYANGView::OnSumAddtwonumbers2)
	ON_COMMAND(ID_OPERATION_TESTPROPERTYPAGE, &CLIXINGYANGView::OnOperationTestpropertypage)
END_MESSAGE_MAP()

// CLIXINGYANGView ����/����

CLIXINGYANGView::CLIXINGYANGView()
{
	// TODO: �ڴ˴���ӹ������
	m_bRed = FALSE;
	m_bGreen = FALSE;
	m_bBlue = FALSE;

	m_strName = L"��С��";
	m_strGender = L"��";
	m_strAge = L"18";
	
	m_bBasketball = FALSE;
	m_bTennis = FALSE;
	m_bTableTennis = FALSE;
	m_bSwimming = FALSE;

	m_strInterest = L"ƹ����";
	m_strJob = _T("����Ա");
	m_strCity = _T("����");
}

CLIXINGYANGView::~CLIXINGYANGView()
{
}

BOOL CLIXINGYANGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CLIXINGYANGView ����
void CLIXINGYANGView::OnDraw(CDC* pDC)
{
	CLIXINGYANGDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	COLORREF color=RGB(m_bRed?255:0,
					   m_bGreen?255:0,
					   m_bBlue?255:0);
	pDC->SetTextColor(color);
	pDC->TextOut(0,0,_T("Hello World!"));

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);

	pDC->TextOut(0, 1 * tm.tmHeight, L"����: " + m_strName);
	pDC->TextOut(0, 2 * tm.tmHeight, L"�Ա�: " + m_strGender);
	pDC->TextOut(0, 3 * tm.tmHeight, L"����: " + m_strAge);	
	pDC->TextOut(0, 4 * tm.tmHeight, _T("��Ȥ���ã�") + m_strInterest);
	pDC->TextOut(0, 5 * tm.tmHeight, _T("������") + m_strJob);
	pDC->TextOut(0, 6 * tm.tmHeight, _T("�����ص㣺") + m_strCity);
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
	CView::AssertValid();
}

void CLIXINGYANGView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLIXINGYANGDoc* CLIXINGYANGView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLIXINGYANGDoc)));
	return (CLIXINGYANGDoc*)m_pDocument;
}
#endif //_DEBUG


// CLIXINGYANGView ��Ϣ�������


void CLIXINGYANGView::OnColorRed()
{
	// TODO: Add your command handler code here
	m_bRed=!m_bRed;
	Invalidate();
}


void CLIXINGYANGView::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bRed);
}


void CLIXINGYANGView::OnColorGreen()
{
	// TODO: Add your command handler code here
	m_bGreen=!m_bGreen;
	Invalidate();
}


void CLIXINGYANGView::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bGreen);
}


void CLIXINGYANGView::OnColorBlue()
{
	// TODO: Add your command handler code here
	m_bBlue=!m_bBlue;
	Invalidate();
}


void CLIXINGYANGView::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_bBlue);
}


void CLIXINGYANGView::OnColorSelectcolor1()
{
	// TODO: Add your command handler code here
	CMySelectColorDlg dlgSelectColor;

	if (dlgSelectColor.DoModal()==IDOK) {
		this->m_bRed = dlgSelectColor.m_bRed;
		this->m_bGreen = dlgSelectColor.m_bGreen;
		this->m_bBlue = dlgSelectColor.m_bBlue;

		Invalidate();
	}
}


void CLIXINGYANGView::OnColorSelectcolor2()
{
	// TODO: Add your command handler code here
	if (!m_dlgSelectColor.m_hWnd)
		m_dlgSelectColor.Create(IDD_SELECTCOLOR);

	m_dlgSelectColor.ShowWindow(SW_SHOW);
}


void CLIXINGYANGView::OnSumAddtwonumbers1()
{
	// TODO: Add your command handler code here
	CMySumDlg dlgSum;

	dlgSum.DoModal();
}


void CLIXINGYANGView::OnSumAddtwonumbers2()
{
	// TODO: Add your command handler code here
	if (!m_dlgSum.m_hWnd)
		m_dlgSum.Create(IDD_SUM);

	m_dlgSum.ShowWindow(SW_SHOW);
}


void CLIXINGYANGView::OnOperationTestpropertypage()
{
	// TODO:  �ڴ���������������
	CPropertySheet sheet;
	CPageSelectColor pageSelectColor;
	CPageAdd2Num pageAdd2Num;
	CPagePersonal pagePersonal;
	CInterestPage pageInterest;
	CJobPage pageJob;
	CPageCtlColor pageCtl;

	// �������ҳ
	sheet.AddPage(&pageSelectColor);
	sheet.AddPage(&pageAdd2Num);
	sheet.AddPage(&pagePersonal);
	sheet.AddPage(&pageInterest);
	sheet.AddPage(&pageJob);
	sheet.AddPage(&pageCtl);

	// ���ԶԻ���
	if (sheet.DoModal() == IDOK) {
		this->m_bRed = pageSelectColor.m_bRed;
		this->m_bGreen = pageSelectColor.m_bGreen;
		this->m_bBlue = pageSelectColor.m_bBlue;

		this->m_strName = pagePersonal.m_strName;
		this->m_strGender = pagePersonal.m_strGender;
		this->m_strAge = pagePersonal.m_strAge;

		m_strInterest = _T("");
		if (pageInterest.m_bTBLTennis)
			m_strInterest += _T(" ƹ���� ");
		if (pageInterest.m_bBSKBall)
			m_strInterest += _T(" ���� ");
		if (pageInterest.m_bSwimming)
			m_strInterest += _T(" ��Ӿ ");
		if (pageInterest.m_bTennis)
			m_strInterest += _T(" ���� ");

		if (pageJob.m_nJob == 0)
			m_strJob = _T("����Ա");
		if (pageJob.m_nJob == 1)
			m_strJob = _T("�������ʦ");
		if (pageJob.m_nJob == 2)
			m_strJob = _T("ϵͳ����ʦ");

		this->m_strCity = pageJob.m_strCity;

		Invalidate();
	}
}
