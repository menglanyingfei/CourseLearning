#pragma once


// CPageSelectColor 对话框

class CPageSelectColor : public CPropertyPage
{
	DECLARE_DYNAMIC(CPageSelectColor)

public:
	CPageSelectColor();
	virtual ~CPageSelectColor();

// 对话框数据
	enum { IDD = IDD_PAGE_SELECTCOLOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bBlue;
	BOOL m_bGreen;
	BOOL m_bRed;
	virtual BOOL OnApply();
	afx_msg void OnClickedGreen();
	afx_msg void OnClickedRed();
	afx_msg void OnClickedBlue();
};
