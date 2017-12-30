
// NetLIXINGYANGChatDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CNetLIXINGYANGChatDlg �Ի���



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


// CNetLIXINGYANGChatDlg ��Ϣ�������

BOOL CNetLIXINGYANGChatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	InitSocket();

	m_structRecvParam.sock = m_socket;
	m_structRecvParam.hWnd = this->m_hWnd;
	m_hThread = CreateThread(NULL, 0, RecvProc, (LPVOID)&m_structRecvParam, 0, NULL);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CNetLIXINGYANGChatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CNetLIXINGYANGChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CNetLIXINGYANGChatDlg::InitSocket()
{
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (INVALID_SOCKET == m_socket) {
		MessageBox(_T("�׽��ִ���ʧ�ܣ�"));
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
		MessageBox(_T("��ʧ�ܣ�"));
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

		sprintf_s(tempBuf, "%s ˵��%s", inet_ntoa(m_addrClient.sin_addr), recvBuf);
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

	this->SendDlgItemMessage(IDC_EDIT_RECEIVE, WM_VSCROLL, SB_BOTTOM, 0); // ʹ���úù��������������·�
	GetDlgItem(IDC_EDIT_RECEIVE)->ShowScrollBar(SB_VERT, TRUE); // ��ʾ��ֱ������
	GetDlgItem(IDC_EDIT_RECEIVE)->ShowScrollBar(SB_HORZ, TRUE); // ��ʾˮƽ������
}


void CNetLIXINGYANGChatDlg::OnEnChangeEditSend()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
