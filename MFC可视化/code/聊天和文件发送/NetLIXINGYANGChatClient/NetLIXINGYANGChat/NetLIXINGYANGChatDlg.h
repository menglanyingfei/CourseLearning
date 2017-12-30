
// NetLIXINGYANGChatDlg.h : 头文件
//

#pragma once

struct RECVPARAM
{
	SOCKET sock;
	HWND hWnd;
};

// CNetLIXINGYANGChatDlg 对话框
class CNetLIXINGYANGChatDlg : public CDialogEx
{
// 构造
public:
	CNetLIXINGYANGChatDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CNetLIXINGYANGChatDlg();

// 对话框数据
	enum { IDD = IDD_NETLIXINGYANGCHAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	SOCKET m_socket;
	static SOCKADDR_IN m_addrSrv;
	BOOL InitSocket();

	RECVPARAM m_structRecvParam;
	HANDLE m_hThread;
	static DWORD WINAPI RecvProc(LPVOID lpParameter);

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnRecvData(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonSend();
	afx_msg void OnClickedButtonOpen();
};
