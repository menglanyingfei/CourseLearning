#pragma once


// CInterestPage �Ի���

class CInterestPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CInterestPage)

public:
	CInterestPage();
	virtual ~CInterestPage();

// �Ի�������
	enum { IDD = IDD_PAGE4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
