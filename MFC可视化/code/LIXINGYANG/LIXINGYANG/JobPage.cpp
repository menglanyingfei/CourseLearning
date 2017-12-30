// JobPage.cpp : 实现文件
//

#include "stdafx.h"
#include "LIXINGYANG.h"
#include "JobPage.h"
#include "afxdialogex.h"


// CJobPage 对话框

IMPLEMENT_DYNAMIC(CJobPage, CPropertyPage)

CJobPage::CJobPage()
	: CPropertyPage(CJobPage::IDD)
	, m_strCity(_T(""))
	, m_nJob(0)
{

}

CJobPage::~CJobPage()
{
}

void CJobPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_LIST_CITY, m_strCity);
	DDX_Radio(pDX, IDC_RADIO_PRO, m_nJob);
}


BEGIN_MESSAGE_MAP(CJobPage, CPropertyPage)
END_MESSAGE_MAP()


// CJobPage 消息处理程序


BOOL CJobPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	((CListBox*)GetDlgItem(IDC_LIST_CITY))->AddString(_T("北京"));
	((CListBox*)GetDlgItem(IDC_LIST_CITY))->AddString(_T("上海"));
	((CListBox*)GetDlgItem(IDC_LIST_CITY))->AddString(_T("深圳"));
	((CListBox*)GetDlgItem(IDC_LIST_CITY))->AddString(_T("天津"));

	((CListBox*)GetDlgItem(IDC_LIST_CITY))->SetCurSel(0);

	((CButton*)GetDlgItem(IDC_RADIO_PRO))->SetCheck(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
