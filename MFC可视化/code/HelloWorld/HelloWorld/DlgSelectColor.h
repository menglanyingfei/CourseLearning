#pragma once


// CDlgSelectColor 对话框

class CDlgSelectColor : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSelectColor)

public:
	CDlgSelectColor(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSelectColor();

// 对话框数据
	enum { IDD = IDD_DIALOG_SELECTCOLOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bBlue;
	BOOL m_bGreen;
	BOOL m_bRed;
	afx_msg void OnBnClickedOk();
};
