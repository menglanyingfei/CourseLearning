#pragma once


// CDlgSelectColor �Ի���

class CDlgSelectColor : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSelectColor)

public:
	CDlgSelectColor(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgSelectColor();

// �Ի�������
	enum { IDD = IDD_DIALOG_SELECTCOLOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bBlue;
	BOOL m_bGreen;
	BOOL m_bRed;
	afx_msg void OnBnClickedOk();
};
