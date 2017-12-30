
// MyBackgroundPICView.cpp : CMyBackgroundPICView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMyBackgroundPICView 构造/析构

CMyBackgroundPICView::CMyBackgroundPICView()
{
	// TODO:  在此处添加构造代码

}

CMyBackgroundPICView::~CMyBackgroundPICView()
{
}

BOOL CMyBackgroundPICView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMyBackgroundPICView 绘制

void CMyBackgroundPICView::OnDraw(CDC* pDC)
{
	CMyBackgroundPICDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
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
	// 全屏化显示图片
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, bmInfo.bmWidth,
		bmInfo.bmHeight, SRCCOPY);
}


// CMyBackgroundPICView 打印

BOOL CMyBackgroundPICView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMyBackgroundPICView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMyBackgroundPICView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMyBackgroundPICView 诊断

#ifdef _DEBUG
void CMyBackgroundPICView::AssertValid() const
{
	CView::AssertValid();
}

void CMyBackgroundPICView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyBackgroundPICDoc* CMyBackgroundPICView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyBackgroundPICDoc)));
	return (CMyBackgroundPICDoc*)m_pDocument;
}
#endif //_DEBUG


// CMyBackgroundPICView 消息处理程序
