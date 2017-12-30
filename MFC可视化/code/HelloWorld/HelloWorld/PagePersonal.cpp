// PagePersonal.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HelloWorld.h"
#include "PagePersonal.h"
#include "afxdialogex.h"


// CPagePersonal �Ի���

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


// CPagePersonal ��Ϣ�������


BOOL CPagePersonal::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	((CComboBox*)GetDlgItem(IDC_COMBO_GENDER))->SetCurSel(0);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
