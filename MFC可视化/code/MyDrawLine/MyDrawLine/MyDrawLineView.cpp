
// MyDrawLineView.cpp : CMyDrawLineView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CMyDrawLineView 构造/析构

CMyDrawLineView::CMyDrawLineView()
{
	// TODO: 在此处添加构造代码
	m_bDraw = FALSE;
	m_hCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);//初始化m_hCursor为十字光标
}

CMyDrawLineView::~CMyDrawLineView()
{
}

BOOL CMyDrawLineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW,
										m_hCursor,
										(HBRUSH)::GetStockObject(BLACK_BRUSH));

	return CView::PreCreateWindow(cs);
}

// CMyDrawLineView 绘制
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


// CMyDrawLineView 打印
BOOL CMyDrawLineView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMyDrawLineView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMyDrawLineView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMyDrawLineView 诊断

#ifdef _DEBUG
void CMyDrawLineView::AssertValid() const
{
	CView::AssertValid();
}

void CMyDrawLineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDrawLineDoc* CMyDrawLineView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDrawLineDoc)));
	return (CMyDrawLineDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyDrawLineView 消息处理程序
// 按住鼠标左键移动
void CMyDrawLineView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_bDraw) {
		CClientDC dc(this);//如果你喜欢画画，你得先准备了画布，画笔，颜料 画画的环境搭建好了，你就可以画画了。 这个画画的环境，就是DC。 
		dc.SetROP2(R2_NOT);
		CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//设备描述表的当前画刷（设备描述表用于应用程序和物理设备之间进行交互）
		CBrush *OldBrush=dc.SelectObject(pBrush);
		
		dc.MoveTo(m_pointOrigin);
		//擦除
		dc.Rectangle(CRect(m_pointOrigin,m_pointCur));
		dc.MoveTo(m_pointOrigin);
		//绘制
		dc.Rectangle(CRect(m_pointOrigin,point));
		m_pointCur = point;
		OldBrush=pBrush;
		
	}
	// 鼠标只要移动就调用
	CView::OnMouseMove(nFlags, point);
}

// 抬起鼠标左键
void CMyDrawLineView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_bDraw) {
		m_bDraw = FALSE;
		ReleaseCapture();
		ClipCursor(NULL);//释放鼠标使用权限（即鼠标可以全屏移动）

		CMyDrawLineDoc* pDoc = GetDocument();
		pDoc->AddLine(m_pointOrigin,point);
		pDoc->ClearArray2Lines();
	}

	CView::OnLButtonUp(nFlags, point);
}

// 按住鼠标左键
void CMyDrawLineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pointOrigin = point;
	m_pointCur = point;

	SetCapture();
	m_bDraw = TRUE;
	//定义矩形区域
	RECT rect;
	GetClientRect(&rect);//取得区域rect
	ClientToScreen(&rect);
	ClipCursor(&rect);

	CView::OnLButtonDown(nFlags, point);
}



void CMyDrawLineView::OnEditUndo()
{
	// TODO: 在此添加命令处理程序代码
	CMyDrawLineDoc* pDoc = GetDocument();
	pDoc->OnUndo();
}


void CMyDrawLineView::OnUpdateEditUndo(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMyDrawLineDoc* pDoc = GetDocument();
	pCmdUI->Enable(pDoc->GetArrayLinesSize());
}


void CMyDrawLineView::OnEditRedo()
{
	// TODO: 在此添加命令处理程序代码
	CMyDrawLineDoc* pDoc = GetDocument();
	pDoc->OnRedo();
}


void CMyDrawLineView::OnUpdateEditRedo(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	CMyDrawLineDoc* pDoc = GetDocument();
	pCmdUI->Enable(pDoc->GetArray2LinesSize());
}
