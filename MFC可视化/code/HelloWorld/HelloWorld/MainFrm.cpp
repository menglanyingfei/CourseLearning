
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_SEPARATOR,			// Mouse move

	ID_INDICATOR_TIME, // Time

	ID_INDICATOR_PROGRESS, // Progress bar 

	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO:  �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

// VM_CREATE, ��ʼ��������ڴ˴�
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO:  �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	SetTimer(1, 1000, NULL); // ms, ��Ϣ������
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

	// ��ȡMenu����
	GetMenu()->GetSubMenu(5)->SetMenuItemBitmaps(
		0, MF_BYPOSITION,
		&m_bitmapRed2, &m_bitmapRed1);
	GetMenu()->GetSubMenu(5)->SetMenuItemBitmaps(
		1, MF_BYPOSITION,
		&m_bitmapGreen2, &m_bitmapGreen1);
	GetMenu()->GetSubMenu(5)->SetMenuItemBitmaps(
		2, MF_BYPOSITION,
		&m_bitmapBlue2, &m_bitmapBlue1); // δѡ��, ѡ��

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������



void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CTime time = CTime::GetCurrentTime();
	CString str = time.Format(L"%H:%M:%S");
	m_wndStatusBar.SetPaneText(2, str);

	// ����
	m_ctrlProgress.StepIt();

	CFrameWnd::OnTimer(nIDEvent);
}


void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CFrameWnd::OnPaint()

	CRect rect;
	m_wndStatusBar.GetItemRect(3, &rect);

	if (m_ctrlProgress.m_hWnd) {
		// ����λ��
		m_ctrlProgress.SetWindowPos(NULL, rect.left, rect.top
			, rect.Width(), rect.Height(), SWP_NOZORDER);

	}
	else {
		m_ctrlProgress.Create(WS_CHILD | WS_VISIBLE, rect, &m_wndStatusBar, 111);
	}
}
