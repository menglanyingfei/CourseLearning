
// LoginDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CLoginDemoDlg �Ի���
class CLoginDemoDlg : public CDialogEx
{
// ����
public:
	CLoginDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOGINDEMO_DIALOG };

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
	CStatic m_Welcome;
	CString m_UserName;
	CString m_UserPassword;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
