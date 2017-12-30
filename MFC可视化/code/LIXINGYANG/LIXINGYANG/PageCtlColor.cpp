// PageCtlColor.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LIXINGYANG.h"
#include "PageCtlColor.h"
#include "afxdialogex.h"

// CPageCtlColor �Ի���

IMPLEMENT_DYNAMIC(CPageCtlColor, CPropertyPage)

CPageCtlColor::CPageCtlColor()
	: CPropertyPage(CPageCtlColor::IDD)
{

}

CPageCtlColor::~CPageCtlColor()
{
}

void CPageCtlColor::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER2, m_ctrlRed);
	//  DDX_Control(pDX, IDC_SLIDER3, m_ctrlBlue);
	//  DDX_Control(pDX, IDC_SLIDER4, m_ctrlGreen);
	DDX_Control(pDX, IDC_SLIDER3, m_ctrlGreen);
	DDX_Control(pDX, IDC_SLIDER4, m_ctrlBlue);
}


BEGIN_MESSAGE_MAP(CPageCtlColor, CPropertyPage)
	ON_WM_HSCROLL()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CPageCtlColor ��Ϣ�������


BOOL CPageCtlColor::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_ctrlRed.SetRange(0, 255);
	m_ctrlGreen.SetRange(0, 255);
	m_ctrlBlue.SetRange(0, 255);

	m_ctrlRed.SetPos(255);
	m_ctrlGreen.SetPos(128);
	m_ctrlBlue.SetPos(128);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CPageCtlColor::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CPropertyPage::OnHScroll(nSBCode, nPos, pScrollBar);
}


HBRUSH CPageCtlColor::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (pWnd->GetDlgCtrlID() == IDC_STATIC)

		pDC->SetTextColor(RGB(m_ctrlRed.GetPos(),
		m_ctrlGreen.GetPos(),
		m_ctrlBlue.GetPos()));

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
