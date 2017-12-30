
// MyKaraokeView.cpp : CMyKaraokeView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMyKaraokeView 构造/析构

CMyKaraokeView::CMyKaraokeView()
{
	// TODO:  在此处添加构造代码
	m_nWidth = 0;
	m_bTimer = FALSE;

}

CMyKaraokeView::~CMyKaraokeView()
{
}

BOOL CMyKaraokeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyKaraokeView 绘制

void CMyKaraokeView::OnDraw(CDC* pDC)
{
	CMyKaraokeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CString str; // L""
	// 版本不同, 加载String table
	str.LoadStringW(IDS_NEWSTRING);

	CRect rect;
	rect.top = 100;
	rect.left = 0;

	CSize size = pDC->GetTextExtent(str);
	rect.bottom = rect.top + size.cy;
	rect.right = rect.left + size.cx;

	COLORREF oldColor;
	// 恢复之前的颜色
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


// CMyKaraokeView 打印

BOOL CMyKaraokeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMyKaraokeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMyKaraokeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMyKaraokeView 诊断

#ifdef _DEBUG
void CMyKaraokeView::AssertValid() const
{
	CView::AssertValid();
}

void CMyKaraokeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyKaraokeDoc* CMyKaraokeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyKaraokeDoc)));
	return (CMyKaraokeDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyKaraokeView 消息处理程序


int CMyKaraokeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(1, 300, NULL);


	return 0;
}


void CMyKaraokeView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m_bTimer = TRUE;
	InvalidateRect(NULL);

	CView::OnTimer(nIDEvent);
}
