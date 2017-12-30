// InterestPage.cpp : 实现文件
//

#include "stdafx.h"
#include "LIXINGYANG.h"
#include "MainFrm.h"
#include "LIXINGYANGDoc.h"
#include "LIXINGYANGView.h"
#include "InterestPage.h"
#include "afxdialogex.h"


// CInterestPage 对话框

IMPLEMENT_DYNAMIC(CInterestPage, CPropertyPage)

CInterestPage::CInterestPage()
	: CPropertyPage(CInterestPage::IDD)
	, m_bBSKBall(FALSE)
	, m_bSwimming(FALSE)
	, m_bTBLTennis(FALSE)
	, m_bTennis(FALSE)
{

}

CInterestPage::~CInterestPage()
{
}

void CInterestPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHK_BSKBALL, m_bBSKBall);
	DDX_Check(pDX, IDC_CHK_SWIMMING, m_bSwimming);
	DDX_Check(pDX, IDC_CHK_TBLTENNIS, m_bTBLTennis);
	DDX_Check(pDX, IDC_CHK_TENNIS, m_bTennis);
}


BEGIN_MESSAGE_MAP(CInterestPage, CPropertyPage)
	ON_BN_CLICKED(IDC_CHK_BSKBALL, &CInterestPage::OnClickedChkBskball)
	ON_BN_CLICKED(IDC_CHK_SWIMMING, &CInterestPage::OnClickedChkSwimming)
	ON_BN_CLICKED(IDC_CHK_TBLTENNIS, &CInterestPage::OnClickedChkTbltennis)
	ON_BN_CLICKED(IDC_CHK_TENNIS, &CInterestPage::OnClickedChkTennis)
END_MESSAGE_MAP()


// CInterestPage 消息处理程序


BOOL CInterestPage::OnApply()
{
	// TODO:  在此添加专用代码和/或调用基类
	UpdateData(TRUE);
	
	((CLIXINGYANGView*)((CMainFrame*)AfxGetMainWnd())->GetActiveView())->m_bTableTennis = this->m_bTBLTennis;
	((CLIXINGYANGView*)((CMainFrame*)AfxGetMainWnd())->GetActiveView())->m_bBasketball = this->m_bBSKBall;
	((CLIXINGYANGView*)((CMainFrame*)AfxGetMainWnd())->GetActiveView())->m_bTennis = this->m_bTennis;
	((CLIXINGYANGView*)((CMainFrame*)AfxGetMainWnd())->GetActiveView())->m_bSwimming = this->m_bSwimming;

	::InvalidateRect(AfxGetMainWnd()->GetSafeHwnd(), NULL, NULL);

	return CPropertyPage::OnApply();
}


void CInterestPage::OnClickedChkBskball()
{
	// TODO:  在此添加控件通知处理程序代码
	SetModified(TRUE);
}


void CInterestPage::OnClickedChkSwimming()
{
	// TODO:  在此添加控件通知处理程序代码
	SetModified(TRUE);
}


void CInterestPage::OnClickedChkTbltennis()
{
	// TODO:  在此添加控件通知处理程序代码
	SetModified(TRUE);
}


void CInterestPage::OnClickedChkTennis()
{
	// TODO:  在此添加控件通知处理程序代码
	SetModified(TRUE);
}
