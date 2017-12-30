#pragma once


// CPageSelectColor �Ի���

class CPageSelectColor : public CPropertyPage
{
	DECLARE_DYNAMIC(CPageSelectColor)

public:
	CPageSelectColor();
	virtual ~CPageSelectColor();

// �Ի�������
	enum { IDD = IDD_PAGE_SELECTCOLOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
