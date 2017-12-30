// PageCtlColor.cpp : 实现文件
//

#include "stdafx.h"
#include "LIXINGYANG.h"
#include "PageCtlColor.h"
#include "afxdialogex.h"

// CPageCtlColor 对话框

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


// CPageCtlColor 消息处理程序


BOOL CPageCtlColor::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_ctrlRed.SetRange(0, 255);
	m_ctrlGreen.SetRange(0, 255);
	m_ctrlBlue.SetRange(0, 255);

	m_ctrlRed.SetPos(255);
	m_ctrlGreen.SetPos(128);
	m_ctrlBlue.SetPos(128);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CPageCtlColor::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CPropertyPage::OnHScroll(nSBCode, nPos, pScrollBar);
}


HBRUSH CPageCtlColor::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CPropertyPage::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID() == IDC_STATIC)

		pDC->SetTextColor(RGB(m_ctrlRed.GetPos(),
		m_ctrlGreen.GetPos(),
		m_ctrlBlue.GetPos()));

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
