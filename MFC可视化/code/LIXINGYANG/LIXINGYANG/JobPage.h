#pragma once


// CJobPage �Ի���

class CJobPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CJobPage)

public:
	CJobPage();
	virtual ~CJobPage();

// �Ի�������
	enum { IDD = IDD_PAGE5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strCity;
	int m_nJob;
	virtual BOOL OnInitDialog();
};
