
// NetLIXINGYANGChatDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "NetLIXINGYANGChat.h"
#include "NetLIXINGYANGChatDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

SOCKET CNetLIXINGYANGChatDlg::m_socketClient;
SOCKADDR_IN CNetLIXINGYANGChatDlg::m_addrClient;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CNetLIXINGYANGChatDlg 对话框



CNetLIXINGYANGChatDlg::CNetLIXINGYANGChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNetLIXINGYANGChatDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNetLIXINGYANGChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNetLIXINGYANGChatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_RECVDATA, OnRecvData)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CNetLIXINGYANGChatDlg::OnClickedButtonSend)
	ON_EN_CHANGE(IDC_EDIT_SEND, &CNetLIXINGYANGChatDlg::OnEnChangeEditSend)
END_MESSAGE_MAP()


// CNetLIXINGYANGChatDlg 消息处理程序

BOOL CNetLIXINGYANGChatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	InitSocket();

	m_structRecvParam.sock = m_socket;
	m_structRecvParam.hWnd = this->m_hWnd;
	m_hThread = CreateThread(NULL, 0, RecvProc, (LPVOID)&m_structRecvParam, 0, NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CNetLIXINGYANGChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CNetLIXINGYANGChatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CNetLIXINGYANGChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CNetLIXINGYANGChatDlg::InitSocket()
{
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == m_socket) {
		MessageBox(_T("套接字创建失败！"));
		return FALSE;
	}

	SOCKADDR_IN addrSock;
	addrSock.sin_family = AF_INET;
	addrSock.sin_port = htons(6000);
	addrSock.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	int retval;
	retval = bind(m_socket, (SOCKADDR*)&addrSock, sizeof(SOCKADDR));
	if (SOCKET_ERROR == retval) {
		closesocket(m_socket);
		MessageBox(_T("绑定失败！"));
		return FALSE;
	}
	listen(m_socket, 5);

	return TRUE;
}

CNetLIXINGYANGChatDlg::~CNetLIXINGYANGChatDlg()
{
	CloseHandle(m_hThread);
}

DWORD WINAPI CNetLIXINGYANGChatDlg::RecvProc(LPVOID lpParameter)
{
	SOCKET sock = ((RECVPARAM*)lpParameter)->sock;
	HWND hWnd = ((RECVPARAM*)lpParameter)->hWnd;

	int len = sizeof(SOCKADDR);

	char recvBuf[200];
	char tempBuf[300];
	int retval;

	m_socketClient = accept(sock, (SOCKADDR*)&m_addrClient, &len);
	while (TRUE) {
		retval = recv(m_socketClient, recvBuf, 200, 0);
		if (SOCKET_ERROR == retval)
			break;

		sprintf_s(tempBuf, "%s 说：%s", inet_ntoa(m_addrClient.sin_addr), recvBuf);
		::PostMessage(hWnd, WM_RECVDATA, 0, (LPARAM)tempBuf);
	}
	return 0;
}

LRESULT CNetLIXINGYANGChatDlg::OnRecvData(WPARAM wParam, LPARAM lParam)
{
	char* c_str = (char*)lParam;
	CString str(c_str);
	CString strTemp;

	GetDlgItemText(IDC_EDIT_RECEIVE, strTemp);
	str += _T("\r\n");
	str += strTemp;
	SetDlgItemText(IDC_EDIT_RECEIVE, str);

	return TRUE;
}


void CNetLIXINGYANGChatDlg::OnClickedButtonSend()
{
	// TODO:  在此添加控件通知处理程序代码
	CString strSend;
	GetDlgItemText(IDC_EDIT_SEND, strSend);
	char c_str[300];
	wcstombs(c_str, strSend, 2 * wcslen(strSend) + 1);

	send(m_socketClient, c_str, strlen(c_str) + 1, 0);
	SetDlgItemText(IDC_EDIT_SEND, _T(""));

	CString strTemp;
	GetDlgItemText(IDC_EDIT_RECEIVE, strTemp);
	strSend += _T("\r\n");
	strSend += strTemp;
	SetDlgItemText(IDC_EDIT_RECEIVE, strSend);

	this->SendDlgItemMessage(IDC_EDIT_RECEIVE, WM_VSCROLL, SB_BOTTOM, 0); // 使设置好滚动条总是在最下方
	GetDlgItem(IDC_EDIT_RECEIVE)->ShowScrollBar(SB_VERT, TRUE); // 显示垂直滚动条
	GetDlgItem(IDC_EDIT_RECEIVE)->ShowScrollBar(SB_HORZ, TRUE); // 显示水平滚动条
}


void CNetLIXINGYANGChatDlg::OnEnChangeEditSend()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
