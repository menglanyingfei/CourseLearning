// PagePersonal.cpp : 实现文件
//

#include "stdafx.h"
#include "LIXINGYANG.h"
#include "MainFrm.h"
#include "LIXINGYANGDoc.h"
#include "LIXINGYANGView.h"

#include "PagePersonal.h"
#include "afxdialogex.h"


// CPagePersonal 对话框

IMPLEMENT_DYNAMIC(CPagePersonal, CPropertyPage)

CPagePersonal::CPagePersonal()
	: CPropertyPage(CPagePersonal::IDD)
	, m_strAge(_T(""))
	, m_strGender(_T(""))
	, m_strName(_T(""))
{

}

CPagePersonal::~CPagePersonal()
{
}

void CPagePersonal::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PAGE_AGE, m_strAge);
	DDX_CBString(pDX, IDC_PAGE_GENDER, m_strGender);
	DDX_Text(pDX, IDC_PAGE_NAME, m_strName);
}


BEGIN_MESSAGE_MAP(CPagePersonal, CPropertyPage)
	ON_EN_CHANGE(IDC_PAGE_NAME, &CPagePersonal::OnEnChangePageName)
	ON_CBN_SELCHANGE(IDC_PAGE_GENDER, &CPagePersonal::OnCbnSelchangePageGender)
	ON_EN_CHANGE(IDC_PAGE_AGE, &CPagePersonal::OnEnChangePageAge)
END_MESSAGE_MAP()


// CPagePersonal 消息处理程序


BOOL CPagePersonal::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	((CComboBox*)GetDlgItem(IDC_PAGE_GENDER))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


BOOL CPagePersonal::OnApply()
{
	// TODO:  在此添加专用代码和/或调用基类
	UpdateData(TRUE);

	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_strName = this->m_strName;
	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_strGender = this->m_strGender;
	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_strAge = this->m_strAge;

	::InvalidateRect(AfxGetMainWnd()->GetSafeHwnd(), NULL, NULL);

	return CPropertyPage::OnApply();
}


void CPagePersonal::OnEnChangePageName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CPropertyPage::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	SetModified(TRUE);
}


void CPagePersonal::OnCbnSelchangePageGender()
{
	// TODO:  在此添加控件通知处理程序代码
	SetModified(TRUE);
}


void CPagePersonal::OnEnChangePageAge()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CPropertyPage::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	SetModified(TRUE);
}
