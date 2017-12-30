#pragma once


// CDlgAdd2Num 对话框

class CDlgAdd2Num : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAdd2Num)

public:
	CDlgAdd2Num(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgAdd2Num();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADD2NUM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nAdd1;
	int m_nAdd2;
	int m_nResult;
	afx_msg void OnClickedIdbButtonResult();
};
