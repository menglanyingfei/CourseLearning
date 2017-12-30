
// NetLIXINGYANGChatDlg.h : ͷ�ļ�
//

#pragma once

struct RECVPARAM
{
	SOCKET sock;
	HWND hWnd;
};

// CNetLIXINGYANGChatDlg �Ի���
class CNetLIXINGYANGChatDlg : public CDialogEx
{
// ����
public:
	CNetLIXINGYANGChatDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CNetLIXINGYANGChatDlg();

// �Ի�������
	enum { IDD = IDD_NETLIXINGYANGCHAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	SOCKET m_socket;
	static SOCKADDR_IN m_addrSrv;
	BOOL InitSocket();

	RECVPARAM m_structRecvParam;
	HANDLE m_hThread;
	static DWORD WINAPI RecvProc(LPVOID lpParameter);

	// ���ɵ���Ϣӳ�亯��
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
