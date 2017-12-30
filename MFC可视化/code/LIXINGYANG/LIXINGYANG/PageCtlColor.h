#pragma once
#include "afxcmn.h"


// CPageCtlColor �Ի���

class CPageCtlColor : public CPropertyPage
{
	DECLARE_DYNAMIC(CPageCtlColor)

public:
	CPageCtlColor();
	virtual ~CPageCtlColor();

// �Ի�������
	enum { IDD = IDD_CONTROLCOLOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_ctrlRed;
	virtual BOOL OnInitDialog();
//	CSliderCtrl m_ctrlBlue;
//	CSliderCtrl m_ctrlGreen;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CSliderCtrl m_ctrlGreen;
	CSliderCtrl m_ctrlBlue;
};
