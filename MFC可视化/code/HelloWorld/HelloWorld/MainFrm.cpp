
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "HelloWorld.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_PAINT()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_SEPARATOR,			// Mouse move

	ID_INDICATOR_TIME, // Time

	ID_INDICATOR_PROGRESS, // Progress bar 

	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO:  在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

// VM_CREATE, 初始化程序放在此处
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	SetTimer(1, 1000, NULL); // ms, 消息处理函数
	CTime time = CTime::GetCurrentTime();
	CString str = time.Format(L"%H:%M:%S");

	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	m_wndStatusBar.SetPaneInfo(2,
		ID_INDICATOR_TIME,
		SBPS_POPOUT, sz.cx);
	m_wndStatusBar.SetPaneText(2, str);

	m_bitmapRed1.LoadBitmapW(IDB_RED1);
	m_bitmapRed2.LoadBitmapW(IDB_RED2);
	m_bitmapGreen1.LoadBitmapW(IDB_GREEN1);
	m_bitmapGreen2.LoadBitmapW(IDB_GREEN2);
	m_bitmapBlue1.LoadBitmapW(IDB_BLUE1);
	m_bitmapBlue2.LoadBitmapW(IDB_BLUE2);

	// 获取Menu对象
	GetMenu()->GetSubMenu(5)->SetMenuItemBitmaps(
		0, MF_BYPOSITION,
		&m_bitmapRed2, &m_bitmapRed1);
	GetMenu()->GetSubMenu(5)->SetMenuItemBitmaps(
		1, MF_BYPOSITION,
		&m_bitmapGreen2, &m_bitmapGreen1);
	GetMenu()->GetSubMenu(5)->SetMenuItemBitmaps(
		2, MF_BYPOSITION,
		&m_bitmapBlue2, &m_bitmapBlue1); // 未选中, 选中

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CTime time = CTime::GetCurrentTime();
	CString str = time.Format(L"%H:%M:%S");
	m_wndStatusBar.SetPaneText(2, str);

	// 调用
	m_ctrlProgress.StepIt();

	CFrameWnd::OnTimer(nIDEvent);
}


void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CFrameWnd::OnPaint()

	CRect rect;
	m_wndStatusBar.GetItemRect(3, &rect);

	if (m_ctrlProgress.m_hWnd) {
		// 设置位置
		m_ctrlProgress.SetWindowPos(NULL, rect.left, rect.top
			, rect.Width(), rect.Height(), SWP_NOZORDER);

	}
	else {
		m_ctrlProgress.Create(WS_CHILD | WS_VISIBLE, rect, &m_wndStatusBar, 111);
	}
}
