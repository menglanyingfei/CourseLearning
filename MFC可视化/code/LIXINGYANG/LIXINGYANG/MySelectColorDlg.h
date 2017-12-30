#pragma once


// CMySelectColorDlg dialog

class CMySelectColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMySelectColorDlg)

public:
	CMySelectColorDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMySelectColorDlg();

// Dialog Data
	enum { IDD = IDD_SELECTCOLOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bRed;
	BOOL m_bGreen;
	BOOL m_bBlue;
	afx_msg void OnBnClickedOk();
};
