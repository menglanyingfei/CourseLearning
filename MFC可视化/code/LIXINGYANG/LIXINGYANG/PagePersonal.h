#pragma once


// CPagePersonal 对话框

class CPagePersonal : public CPropertyPage
{
	DECLARE_DYNAMIC(CPagePersonal)

public:
	CPagePersonal();
	virtual ~CPagePersonal();

// 对话框数据
	enum { IDD = IDD_PAGE_PERSONAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strAge;
	CString m_strGender;
	CString m_strName;
	virtual BOOL OnInitDialog();
	virtual BOOL OnApply();
	afx_msg void OnEnChangePageName();
	afx_msg void OnCbnSelchangePageGender();
	afx_msg void OnEnChangePageAge();
};
