// PageSelectColor.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HelloWorld.h"
#include "MainFrm.h"
#include "HelloWorldDoc.h"
#include "HelloWorldView.h"
#include "PageSelectColor.h"
#include "afxdialogex.h"


// CPageSelectColor �Ի���

IMPLEMENT_DYNAMIC(CPageSelectColor, CPropertyPage)

CPageSelectColor::CPageSelectColor()
	: CPropertyPage(CPageSelectColor::IDD)
	, m_bBlue(FALSE)
	, m_bGreen(FALSE)
	, m_bRed(FALSE)
{

}

CPageSelectColor::~CPageSelectColor()
{
}

void CPageSelectColor::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_BLUE, m_bBlue);
	DDX_Check(pDX, IDC_CHECK_GREEN, m_bGreen);
	DDX_Check(pDX, IDC_CHECK_RED, m_bRed);
}


BEGIN_MESSAGE_MAP(CPageSelectColor, CPropertyPage)
	ON_BN_CLICKED(IDC_CHECK_BLUE, &CPageSelectColor::OnClickedCheckBlue)
	ON_BN_CLICKED(IDC_CHECK_GREEN, &CPageSelectColor::OnClickedCheckGreen)
	ON_BN_CLICKED(IDC_CHECK_RED, &CPageSelectColor::OnClickedCheckRed)
END_MESSAGE_MAP()


// CPageSelectColor ��Ϣ�������


void CPageSelectColor::OnClickedCheckBlue()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetModified(TRUE);

}


void CPageSelectColor::OnClickedCheckGreen()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetModified(TRUE);
}


void CPageSelectColor::OnClickedCheckRed()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetModified(TRUE);
}


BOOL CPageSelectColor::OnApply()
{
	// TODO:  �ڴ����ר�ô����/����û���
	UpdateData(TRUE);

	((CHelloWorldView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bRed = this->m_bRed;
	((CHelloWorldView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bGreen = this->m_bGreen;
	((CHelloWorldView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bBlue = this->m_bBlue;

	::InvalidateRect(AfxGetMainWnd()->GetSafeHwnd(), NULL, NULL);
	
	return CPropertyPage::OnApply();
}
