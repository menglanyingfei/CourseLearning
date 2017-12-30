// MySumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LIXINGYANG.h"
#include "MySumDlg.h"
#include "afxdialogex.h"


// CMySumDlg dialog

IMPLEMENT_DYNAMIC(CMySumDlg, CDialogEx)

CMySumDlg::CMySumDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMySumDlg::IDD, pParent)
{

	m_nAdd1 = 0;
	m_nAdd2 = 0;
	m_nSum = 0;
}

CMySumDlg::~CMySumDlg()
{
}

void CMySumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ADD1, m_nAdd1);
	DDX_Text(pDX, IDC_ADD2, m_nAdd2);
	DDX_Text(pDX, IDC_SUM, m_nSum);
}


BEGIN_MESSAGE_MAP(CMySumDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ADD, &CMySumDlg::OnClickedAdd)
END_MESSAGE_MAP()


// CMySumDlg message handlers


void CMySumDlg::OnClickedAdd()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_nSum=m_nAdd1+m_nAdd2;

	UpdateData(FALSE);
}
