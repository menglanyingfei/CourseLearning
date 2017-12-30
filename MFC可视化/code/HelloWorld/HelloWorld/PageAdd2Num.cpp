// PageAdd2Num.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HelloWorld.h"
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
	DDX_Text(pDX, IDC_EDIT_ADD1, m_nAdd1);
	DDX_Text(pDX, IDC_EDIT_ADD2, m_nAdd2);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_nResult);
}


BEGIN_MESSAGE_MAP(CPageAdd2Num, CPropertyPage)
	ON_BN_CLICKED(IDB_BUTTON_RESULT, &CPageAdd2Num::OnClickedIdbButtonResult)
END_MESSAGE_MAP()


// CPageAdd2Num ��Ϣ�������


void CPageAdd2Num::OnClickedIdbButtonResult()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);

	m_nResult = m_nAdd1 + m_nAdd2;

	UpdateData(FALSE);
}
