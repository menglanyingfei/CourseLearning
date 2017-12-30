#pragma once


// CMySumDlg dialog

class CMySumDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMySumDlg)

public:
	CMySumDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMySumDlg();

// Dialog Data
	enum { IDD = IDD_SUM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int m_nAdd1;
	int m_nAdd2;
	int m_nSum;
	afx_msg void OnClickedAdd();
};
