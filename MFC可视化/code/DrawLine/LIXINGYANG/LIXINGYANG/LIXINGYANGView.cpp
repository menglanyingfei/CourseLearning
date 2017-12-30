
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLIXINGYANGView

IMPLEMENT_DYNCREATE(CLIXINGYANGView, CScrollView)

BEGIN_MESSAGE_MAP(CLIXINGYANGView, CScrollView)
	// 标准打印命令
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

// CLIXINGYANGView 构造/析构

CLIXINGYANGView::CLIXINGYANGView()
{
	// TODO: 在此处添加构造代码
	m_bDraw = FALSE;
	// 调入标准的鼠标
	m_hCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);

	m_hCursorArrow = AfxGetApp()->LoadStandardCursor(IDC_ARROW);

}

CLIXINGYANGView::~CLIXINGYANGView()
{
}

BOOL CLIXINGYANGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	// 修改缺省的窗口类, 新鼠标光标, 水平变化
	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW, m_hCursorArrow,
		(HBRUSH)::GetStockObject(BLACK_BRUSH));

	return CScrollView::PreCreateWindow(cs);
}

// CLIXINGYANGView 绘制

void CLIXINGYANGView::OnDraw(CDC* pDC)
{
	CLIXINGYANGDoc* pDoc = GetDocument();
	// 对于文档-视图结构, 数据 -> 文档; 对数据的操作以及显示 -> 视图
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->SetROP2(R2_WHITE);
	pDoc->OnDraw(pDC);

	// 创建一个画笔
	CPen pen(PS_SOLID, 5, RGB(255, 255, 0));
	// 将新画笔选入设备上下文
	CPen* pOldPen = pDC->SelectObject(&pen);
	// 使用新画笔绘图
	pDC->SetROP2(R2_COPYPEN);
	// 获取Scroll页面的大小(逻辑大小)
	CSize size = GetTotalSize();

	// 绘制边界线
	pDC->MoveTo(size.cx, 0);
	pDC->LineTo(size.cx, size.cy);
	pDC->LineTo(0, size.cy);
	// 还原旧画笔
	pDC->SelectObject(pOldPen);

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
	CScrollView::AssertValid();
}

void CLIXINGYANGView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CLIXINGYANGDoc* CLIXINGYANGView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLIXINGYANGDoc)));
	return (CLIXINGYANGDoc*)m_pDocument;
}
#endif //_DEBUG


// CLIXINGYANGView 消息处理程序


void CLIXINGYANGView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this); // 获取当前设备上下文
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);

	CSize sizeScroll = GetTotalSize();
	CRect rectScroll(0, 0, sizeScroll.cx, sizeScroll.cy);
	if (!rectScroll.PtInRect(point))
		::SetCursor(m_hCursorArrow);
	else
		::SetCursor(m_hCursor);

	if (m_bDraw) {
		

		dc.SetROP2(R2_NOT); // 设置绘制模式为"像素取反"

		CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH)); //设备描述表的当前画刷（设备描述表用于应用程序和物理设备之间进行交互）
		CBrush *OldBrush = dc.SelectObject(pBrush);
		//dc.MoveTo(m_pointOrigin); // 绘制线段1(抹掉原来的线段)
		//dc.LineTo(m_pointCur);

		//dc.MoveTo(m_pointOrigin); // 绘制线段2(绘制新的线段)
		//dc.LineTo(point);

		dc.Rectangle(CRect(m_pointOrigin, m_pointCur));
		dc.Rectangle(CRect(m_pointOrigin, point));

		m_pointCur = point; // 保存当前鼠标位置
		OldBrush = pBrush;
	}
	CScrollView::OnMouseMove(nFlags, point);
}


void CLIXINGYANGView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	// 客户区设备上下文
	CClientDC dc(this);
	// 准备设备上下文
	OnPrepareDC(&dc);
	// 设备坐标到逻辑坐标
	dc.DPtoLP(&point);

	CSize size = GetTotalSize(); // 获取Scroll页面大小
	CRect rectScroll(0, 0, size.cx, size.cy); // Scroll页面Rect
	if (!rectScroll.PtInRect(point)) // 鼠标点击点是否在Scroll页面区域
		return;

	m_pointOrigin = point;
	m_pointCur = m_pointOrigin; // 保存鼠标位置信息

	SetCapture(); // 捕获鼠标
	m_bDraw = TRUE; // 允许开始绘制

	RECT rect;
	GetClientRect(&rect); // 获取客户区区域

	dc.LPtoDP(&rectScroll); // 将Scroll页面区域转换到设备坐标

	CRect resultRect;
	resultRect.IntersectRect(&rect, &rectScroll); // 计算两个区域重叠部分

	ClientToScreen(&resultRect); // 将客户区逻辑坐标转换成屏幕坐标

	ClipCursor(&resultRect); // 将鼠标活动范围限定在该区域

	CScrollView::OnLButtonDown(nFlags, point);
}


void CLIXINGYANGView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (m_bDraw) {
		m_bDraw = FALSE; // 绘制结束
		ReleaseCapture(); // 释放"鼠标捕获"
		ClipCursor(NULL); // 取消"限定鼠标"
		// View类中获取Doc指针 添加线段
		CLIXINGYANGDoc* pDoc = GetDocument();

		CClientDC dc(this);
		OnPrepareDC(&dc);

		dc.DPtoLP(&point);

		// 待修改!
		//pDoc->AddLine(m_pointOrigin, point);		
		//pDoc->AddView();

		pDoc->AddLine(m_pointOrigin, point);
		
		pDoc->ClearArray2Lines();
	}

	CScrollView::OnLButtonUp(nFlags, point);
}


void CLIXINGYANGView::OnEditRedo()
{
	// TODO:  在此添加命令处理程序代码
	CLIXINGYANGDoc* pDoc = GetDocument();
	pDoc->OnRedo();
}


void CLIXINGYANGView::OnUpdateEditRedo(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	CLIXINGYANGDoc* pDoc = GetDocument();
	pCmdUI->Enable(pDoc->GetArray2LinesSize());
}


void CLIXINGYANGView::OnEditUndo()
{
	// TODO:  在此添加命令处理程序代码
	CLIXINGYANGDoc* pDoc = GetDocument();
	// 在视图类中获取文档类对象的函数
	pDoc->OnUndo();
}


void CLIXINGYANGView::OnUpdateEditUndo(CCmdUI *pCmdUI)
{
	// TODO:  在此添加命令更新用户界面处理程序代码
	CLIXINGYANGDoc* pDoc = GetDocument();

	pCmdUI->Enable(pDoc->GetArrayLinesSize());

}


void CLIXINGYANGView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
	// Scroll页面大小
	CSize size;
	size.cx = 640;
	size.cy = 480;
	SetScrollSizes(MM_TEXT, size);

}