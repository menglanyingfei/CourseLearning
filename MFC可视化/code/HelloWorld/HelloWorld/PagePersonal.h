#pragma once


// CPagePersonal �Ի���

class CPagePersonal : public CPropertyPage
{
	DECLARE_DYNAMIC(CPagePersonal)

public:
	CPagePersonal();
	virtual ~CPagePersonal();

// �Ի�������
	enum { IDD = IDD_PAGE_PERSONAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strGender;
	CString m_strAge;
	CString m_strName;
	virtual BOOL OnInitDialog();
};
