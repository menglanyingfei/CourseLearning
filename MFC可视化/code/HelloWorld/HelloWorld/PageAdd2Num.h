#pragma once


// CPageAdd2Num �Ի���

class CPageAdd2Num : public CPropertyPage
{
	DECLARE_DYNAMIC(CPageAdd2Num)

public:
	CPageAdd2Num();
	virtual ~CPageAdd2Num();

// �Ի�������
	enum { IDD = IDD_PAGE_ADD2NUM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nAdd1;
	int m_nAdd2;
	int m_nResult;
	afx_msg void OnClickedIdbButtonResult();
};
