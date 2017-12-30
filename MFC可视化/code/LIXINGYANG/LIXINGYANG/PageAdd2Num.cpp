// PageAdd2Num.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LIXINGYANG.h"
#include "PageAdd2Num.h"
#include "afxdialogex.h"


// CPageAdd2Num �Ի���

IMPLEMENT_DYNAMIC(CPageAdd2Num, CPropertyPage)

CPageAdd2Num::CPageAdd2Num()
	: CPropertyPage(CPageAdd2Num::IDD)
	, m_nAdd1(0)
	, m_nAdd2(0)
	, m_nResult(0)
{

}

CPageAdd2Num::~CPageAdd2Num()
{
}

void CPageAdd2Num::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PAGE_ADD1, m_nAdd1);
	DDX_Text(pDX, IDC_PAGE_ADD2, m_nAdd2);
	DDX_Text(pDX, IDC_PAGE_SUM, m_nResult);
}


BEGIN_MESSAGE_MAP(CPageAdd2Num, CPropertyPage)
	ON_BN_CLICKED(IDB_PAGE_ADDRESULT, &CPageAdd2Num::OnBnClickedPageAddresult)
END_MESSAGE_MAP()


// CPageAdd2Num ��Ϣ�������


void CPageAdd2Num::OnBnClickedPageAddresult()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	m_nResult = m_nAdd1 + m_nAdd2;

	UpdateData(FALSE);
}
