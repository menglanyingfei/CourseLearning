// JobPage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LIXINGYANG.h"
#include "JobPage.h"
#include "afxdialogex.h"


// CJobPage �Ի���

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


// CJobPage ��Ϣ�������


BOOL CJobPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	((CListBox*)GetDlgItem(IDC_LIST_CITY))->AddString(_T("����"));
	((CListBox*)GetDlgItem(IDC_LIST_CITY))->AddString(_T("�Ϻ�"));
	((CListBox*)GetDlgItem(IDC_LIST_CITY))->AddString(_T("����"));
	((CListBox*)GetDlgItem(IDC_LIST_CITY))->AddString(_T("���"));

	((CListBox*)GetDlgItem(IDC_LIST_CITY))->SetCurSel(0);

	((CButton*)GetDlgItem(IDC_RADIO_PRO))->SetCheck(TRUE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}
