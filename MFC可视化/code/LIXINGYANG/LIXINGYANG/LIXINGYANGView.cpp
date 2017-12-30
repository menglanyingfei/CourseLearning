
// LIXINGYANGView.cpp : CLIXINGYANGView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CLIXINGYANGView 构造/析构

CLIXINGYANGView::CLIXINGYANGView()
{
	// TODO: 在此处添加构造代码
	m_bRed = FALSE;
	m_bGreen = FALSE;
	m_bBlue = FALSE;

	m_strName = L"李小阳";
	m_strGender = L"男";
	m_strAge = L"18";
	
	m_bBasketball = FALSE;
	m_bTennis = FALSE;
	m_bTableTennis = FALSE;
	m_bSwimming = FALSE;

	m_strInterest = L"乒乓球";
	m_strJob = _T("程序员");
	m_strCity = _T("北京");
}

CLIXINGYANGView::~CLIXINGYANGView()
{
}

BOOL CLIXINGYANGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CLIXINGYANGView 绘制
void CLIXINGYANGView::OnDraw(CDC* pDC)
{
	CLIXINGYANGDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	COLORREF color=RGB(m_bRed?255:0,
					   m_bGreen?255:0,
					   m_bBlue?255:0);
	pDC->SetTextColor(color);
	pDC->TextOut(0,0,_T("Hello World!"));

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);

	pDC->TextOut(0, 1 * tm.tmHeight, L"姓名: " + m_strName);
	pDC->TextOut(0, 2 * tm.tmHeight, L"性别: " + m_strGender);
	pDC->TextOut(0, 3 * tm.tmHeight, L"年龄: " + m_strAge);	
	pDC->TextOut(0, 4 * tm.tmHeight, _T("兴趣爱好：") + m_strInterest);
	pDC->TextOut(0, 5 * tm.tmHeight, _T("工作：") + m_strJob);
	pDC->TextOut(0, 6 * tm.tmHeight, _T("工作地点：") + m_strCity);
}


// CLIXINGYANGView 打印

BOOL CLIXINGYANGView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CLIXINGYANGView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CLIXINGYANGView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CLIXINGYANGView 诊断

#ifdef _DEBUG
void CLIXINGYANGView::AssertValid() const
{
	CView::AssertValid();
}

void CLIXINGYANGView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLIXINGYANGDoc* CLIXINGYANGView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLIXINGYANGDoc)));
	return (CLIXINGYANGDoc*)m_pDocument;
}
#endif //_DEBUG


// CLIXINGYANGView 消息处理程序


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
	// TODO:  在此添加命令处理程序代码
	CPropertySheet sheet;
	CPageSelectColor pageSelectColor;
	CPageAdd2Num pageAdd2Num;
	CPagePersonal pagePersonal;
	CInterestPage pageInterest;
	CJobPage pageJob;
	CPageCtlColor pageCtl;

	// 添加属性页
	sheet.AddPage(&pageSelectColor);
	sheet.AddPage(&pageAdd2Num);
	sheet.AddPage(&pagePersonal);
	sheet.AddPage(&pageInterest);
	sheet.AddPage(&pageJob);
	sheet.AddPage(&pageCtl);

	// 属性对话框
	if (sheet.DoModal() == IDOK) {
		this->m_bRed = pageSelectColor.m_bRed;
		this->m_bGreen = pageSelectColor.m_bGreen;
		this->m_bBlue = pageSelectColor.m_bBlue;

		this->m_strName = pagePersonal.m_strName;
		this->m_strGender = pagePersonal.m_strGender;
		this->m_strAge = pagePersonal.m_strAge;

		m_strInterest = _T("");
		if (pageInterest.m_bTBLTennis)
			m_strInterest += _T(" 乒乓球 ");
		if (pageInterest.m_bBSKBall)
			m_strInterest += _T(" 篮球 ");
		if (pageInterest.m_bSwimming)
			m_strInterest += _T(" 游泳 ");
		if (pageInterest.m_bTennis)
			m_strInterest += _T(" 网球 ");

		if (pageJob.m_nJob == 0)
			m_strJob = _T("程序员");
		if (pageJob.m_nJob == 1)
			m_strJob = _T("软件工程师");
		if (pageJob.m_nJob == 2)
			m_strJob = _T("系统分析师");

		this->m_strCity = pageJob.m_strCity;

		Invalidate();
	}
}
