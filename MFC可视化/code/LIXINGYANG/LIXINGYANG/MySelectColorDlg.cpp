// MySelectColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LIXINGYANG.h"
#include "MainFrm.h"
#include "LIXINGYANGDoc.h"
#include "LIXINGYANGView.h"
#include "MySelectColorDlg.h"
#include "afxdialogex.h"


// CMySelectColorDlg dialog

IMPLEMENT_DYNAMIC(CMySelectColorDlg, CDialogEx)

CMySelectColorDlg::CMySelectColorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMySelectColorDlg::IDD, pParent)
{

}

CMySelectColorDlg::~CMySelectColorDlg()
{
}

void CMySelectColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_RED, m_bRed);
	DDX_Check(pDX, IDC_GREEN, m_bGreen);
	DDX_Check(pDX, IDC_BLUE, m_bBlue);
}


BEGIN_MESSAGE_MAP(CMySelectColorDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMySelectColorDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMySelectColorDlg message handlers


void CMySelectColorDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bRed = this->m_bRed;
	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bGreen = this->m_bGreen;
	((CLIXINGYANGView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bBlue = this->m_bBlue;

	::InvalidateRect(((CMainFrame*)AfxGetMainWnd())->GetSafeHwnd(),NULL,NULL);

	CDialogEx::OnOK();
}
