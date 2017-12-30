#pragma once


// CInterestPage 对话框

class CInterestPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CInterestPage)

public:
	CInterestPage();
	virtual ~CInterestPage();

// 对话框数据
	enum { IDD = IDD_PAGE4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bBSKBall;
	BOOL m_bSwimming;
	BOOL m_bTBLTennis;
	BOOL m_bTennis;
	virtual BOOL OnApply();
	afx_msg void OnClickedChkBskball();
	afx_msg void OnClickedChkSwimming();
	afx_msg void OnClickedChkTbltennis();
	afx_msg void OnClickedChkTennis();
};
