#pragma once


// CDlgAdd2Num �Ի���

class CDlgAdd2Num : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAdd2Num)

public:
	CDlgAdd2Num(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgAdd2Num();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD2NUM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_nAdd1;
	int m_nAdd2;
	int m_nResult;
	afx_msg void OnClickedIdbButtonResult();
};
