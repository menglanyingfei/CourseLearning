#pragma once


// CManagerDlg �Ի���

class CManagerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CManagerDlg)

public:
	CManagerDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CManagerDlg();

// �Ի�������
	enum { IDD = IDD_MANAGER 
	};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
