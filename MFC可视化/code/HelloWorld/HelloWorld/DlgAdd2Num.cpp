// DlgAdd2Num.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "HelloWorld.h"
#include "DlgAdd2Num.h"
#include "afxdialogex.h"


// CDlgAdd2Num �Ի���

IMPLEMENT_DYNAMIC(CDlgAdd2Num, CDialogEx)

CDlgAdd2Num::CDlgAdd2Num(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgAdd2Num::IDD, pParent)
	, m_nAdd1(0)
	, m_nAdd2(0)
	, m_nResult(0)
{

}

CDlgAdd2Num::~CDlgAdd2Num()
{
}

void CDlgAdd2Num::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ADD1, m_nAdd1);
	DDX_Text(pDX, IDC_EDIT_ADD2, m_nAdd2);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_nResult);
}


BEGIN_MESSAGE_MAP(CDlgAdd2Num, CDialogEx)
	ON_BN_CLICKED(IDB_BUTTON_RESULT, &CDlgAdd2Num::OnClickedIdbButtonResult)
END_MESSAGE_MAP()


// CDlgAdd2Num ��Ϣ�������


void CDlgAdd2Num::OnClickedIdbButtonResult()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// �ؼ�->����
	UpdateData(TRUE);

	m_nResult = m_nAdd1 + m_nAdd2;

	// ����->�ؼ�(����)
	UpdateData(FALSE);
}
