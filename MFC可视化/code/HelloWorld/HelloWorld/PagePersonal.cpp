// PagePersonal.cpp : 实现文件
//

#include "stdafx.h"
#include "HelloWorld.h"
#include "PagePersonal.h"
#include "afxdialogex.h"


// CPagePersonal 对话框

IMPLEMENT_DYNAMIC(CPagePersonal, CPropertyPage)

CPagePersonal::CPagePersonal()
	: CPropertyPage(CPagePersonal::IDD)
	, m_strGender(_T(""))
	, m_strAge(_T(""))
	, m_strName(_T(""))
{

}

CPagePersonal::~CPagePersonal()
{
}

void CPagePersonal::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_GENDER, m_strGender);
	DDX_Text(pDX, IDC_EDIT_AGE, m_strAge);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
}


BEGIN_MESSAGE_MAP(CPagePersonal, CPropertyPage)
END_MESSAGE_MAP()


// CPagePersonal 消息处理程序


BOOL CPagePersonal::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	((CComboBox*)GetDlgItem(IDC_COMBO_GENDER))->SetCurSel(0);

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
