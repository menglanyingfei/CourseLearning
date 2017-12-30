
// HelloWorldView.cpp : CHelloWorldView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CHelloWorldView 构造/析构

CHelloWorldView::CHelloWorldView()
{
	// TODO:  在此处添加构造代码, 初始化
	m_bRed = FALSE;
	m_bGreen = FALSE;
	m_bBlue = FALSE;

	m_strName = L"李";
	m_strGender = L"男";
	m_strAge = L"20";
}

CHelloWorldView::~CHelloWorldView()
{
}

BOOL CHelloWorldView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CHelloWorldView 绘制
// 数据显示
void CHelloWorldView::OnDraw(CDC* pDC)
{
	// 获取与视图类对应的文档类的对象
	CHelloWorldDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	COLORREF color = RGB(
		m_bRed ? 255 : 0,
		m_bGreen ? 255 : 0,
		m_bBlue ? 255 : 0);
	pDC->SetTextColor(color);
	// 输出Hello World
	pDC->TextOut(0, 0, L"Hello World"); // _T("HelloWorld")

	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);

	pDC->TextOut(0, 1 * tm.tmHeight, L"姓名: " + m_strName);
	pDC->TextOut(0, 2 * tm.tmHeight, L"性别: " + m_strGender);
	pDC->TextOut(0, 3 * tm.tmHeight, L"年龄: " + m_strAge);
	
}

LRESULT CHelloWorldView::OnHide(WPARAM wParam, LPARAM lParam) {
	MessageBox(L"Hide");

	return 0;
}

// CHelloWorldView 打印

BOOL CHelloWorldView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CHelloWorldView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CHelloWorldView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CHelloWorldView 诊断

#ifdef _DEBUG
void CHelloWorldView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloWorldView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloWorldDoc* CHelloWorldView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloWorldDoc)));
	return (CHelloWorldDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloWorldView 消息处理程序


void CHelloWorldView::OnTestmessageSendmessage()
{
	// TODO:  在此添加命令处理程序代码
	PostMessage(WM_HIDE, 0, 0);
}


void CHelloWorldView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CString str;
	CStatusBar* pStatus;
	// 类似C printf()
	str.Format(L"X=%d, Y=%d", point.x, point.y);
	// 应用程序对象, 主框架对象, 获取主框架窗口下的某个小窗口对象
	pStatus = (CStatusBar*)(AfxGetApp()->m_pMainWnd->
		GetDescendantWindow(AFX_IDW_STATUS_BAR));
	// 状态栏窗口对象
	pStatus->SetPaneText(1, str);

	CView::OnMouseMove(nFlags, point);
}


void CHelloWorldView::OnColorRed()
{
	// TODO:  在此添加命令处理程序代码
	m_bRed = !m_bRed;
	// 刷新窗口
	Invalidate();
}


void CHelloWorldView::OnUpdateColorRed(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_bRed);
}


void CHelloWorldView::OnColorGreen()
{
	// TODO:  在此添加命令处理程序代码
	m_bGreen = !m_bGreen;
	// 刷新窗口
	Invalidate();
}


void CHelloWorldView::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_bGreen);
}


void CHelloWorldView::OnColorBlue()
{
	// TODO:  在此添加命令处理程序代码
	m_bBlue = !m_bBlue;
	// 刷新窗口
	Invalidate();
}


void CHelloWorldView::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_bBlue);
}


void CHelloWorldView::OnColorSelectcolor()
{
	// TODO:  在此添加命令处理程序代码
	CDlgSelectColor dlgSelectColor;
	// 模式对话框
	if (dlgSelectColor.DoModal() == IDOK) {
		this->m_bRed = dlgSelectColor.m_bRed;
		this->m_bGreen = dlgSelectColor.m_bGreen;
		this->m_bBlue = dlgSelectColor.m_bBlue;

		// 重新刷新
		Invalidate();
	}
}


void CHelloWorldView::OnColorSelectcolorUnModel()
{
	// TODO:  在此添加命令处理程序代码
	// 非模式对话框
	if (!m_dlgSelectColor.m_hWnd)
		m_dlgSelectColor.Create(IDD_DIALOG_SELECTCOLOR);

	m_dlgSelectColor.ShowWindow(SW_SHOW);
}


void CHelloWorldView::OnSumAdd2num()
{
	// TODO:  在此添加命令处理程序代码
	CDlgAdd2Num dlgAdd2Num;

	dlgAdd2Num.DoModal();
}


void CHelloWorldView::OnSumAdd2numUnModal()
{
	// TODO:  在此添加命令处理程序代码
	if (!m_dlgAdd2Num.m_hWnd)
		m_dlgAdd2Num.Create(IDD_DIALOG_ADD2NUM);

	m_dlgAdd2Num.ShowWindow(SW_SHOW);


}


void CHelloWorldView::OnOperationTestpropertypage()
{
	// TODO:  在此添加命令处理程序代码
	CPropertySheet sheet;
	CPageSelectColor pageSelectColor;
	CPageAdd2Num pageAdd2Num;
	CPagePersonal pagePersonal;

	// 添加属性页
	sheet.AddPage(&pageSelectColor);
	sheet.AddPage(&pageAdd2Num);
	sheet.AddPage(&pagePersonal);

	// 属性对话框
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










