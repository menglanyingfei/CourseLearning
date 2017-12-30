#pragma once


// CJobPage 对话框

class CJobPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CJobPage)

public:
	CJobPage();
	virtual ~CJobPage();

// 对话框数据
	enum { IDD = IDD_PAGE5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strCity;
	int m_nJob;
	virtual BOOL OnInitDialog();
};
