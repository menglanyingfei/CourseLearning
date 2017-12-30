// PagePersonal.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LIXINGYANG.h"
#include "MainFrm.h"
#include "LIXINGYANGDoc.h"
#include "LIXINGYANGView.h"

#include "PagePersonal.h"
#include "afxdialogex.h"


// CPagePersonal �Ի���

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


// CPagePersonal ��Ϣ�������


BOOL CPagePersonal::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	((CComboBox*)GetDlgItem(IDC_PAGE_GENDER))->SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


BOOL CPagePersonal::OnApply()
{
	// TODO:  �ڴ����ר�ô����/����û���
	UpdateData(TRUE);

	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_strName = this->m_strName;
	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_strGender = this->m_strGender;
	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_strAge = this->m_strAge;

	::InvalidateRect(AfxGetMainWnd()->GetSafeHwnd(), NULL, NULL);

	return CPropertyPage::OnApply();
}


void CPagePersonal::OnEnChangePageName()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetModified(TRUE);
}


void CPagePersonal::OnCbnSelchangePageGender()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetModified(TRUE);
}


void CPagePersonal::OnEnChangePageAge()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CPropertyPage::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetModified(TRUE);
}
