
// MyLIXINGYANGDLLDlg.h : ͷ�ļ�
//

#pragma once


// CMyLIXINGYANGDLLDlg �Ի���
class CMyLIXINGYANGDLLDlg : public CDialogEx
{
// ����
public:
	CMyLIXINGYANGDLLDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYLIXINGYANGDLL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nNum;
	afx_msg void OnClickedButtonDcall();
	afx_msg void OnClickedButtonScall();
	afx_msg void OnClickedButtonDllSort();
};
