// PageSelectColor.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LIXINGYANG.h"
#include "MainFrm.h"
#include "LIXINGYANGDoc.h"
#include "LIXINGYANGView.h"
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
	DDX_Check(pDX, IDC_BLUE, m_bBlue);
	DDX_Check(pDX, IDC_GREEN, m_bGreen);
	DDX_Check(pDX, IDC_RED, m_bRed);
}


BEGIN_MESSAGE_MAP(CPageSelectColor, CPropertyPage)
	ON_BN_CLICKED(IDC_GREEN, &CPageSelectColor::OnClickedGreen)
	ON_BN_CLICKED(IDC_RED, &CPageSelectColor::OnClickedRed)
	ON_BN_CLICKED(IDC_BLUE, &CPageSelectColor::OnClickedBlue)
END_MESSAGE_MAP()


// CPageSelectColor ��Ϣ�������


BOOL CPageSelectColor::OnApply()
{
	// TODO:  �ڴ����ר�ô����/����û���
	UpdateData(TRUE);

	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bRed = this->m_bRed;
	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bGreen = this->m_bGreen;
	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bBlue = this->m_bBlue;

	::InvalidateRect(AfxGetMainWnd()->GetSafeHwnd(), NULL, NULL);

	return CPropertyPage::OnApply();
}


void CPageSelectColor::OnClickedGreen()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetModified(TRUE);
}

void CPageSelectColor::OnClickedRed()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetModified(TRUE);
}


void CPageSelectColor::OnClickedBlue()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SetModified(TRUE);
}
