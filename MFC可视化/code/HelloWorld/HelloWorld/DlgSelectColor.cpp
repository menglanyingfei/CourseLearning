// DlgSelectColor.cpp : 实现文件
//

#include "stdafx.h"
#include "HelloWorld.h"
#include "DlgSelectColor.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "HelloWorldDoc.h"
#include "HelloWorldView.h"

// CDlgSelectColor 对话框

IMPLEMENT_DYNAMIC(CDlgSelectColor, CDialogEx)

CDlgSelectColor::CDlgSelectColor(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgSelectColor::IDD, pParent)
	, m_bBlue(FALSE)
	, m_bGreen(FALSE)
	, m_bRed(FALSE)
{

}

CDlgSelectColor::~CDlgSelectColor()
{
}

void CDlgSelectColor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_BLUE, m_bBlue);
	DDX_Check(pDX, IDC_CHECK_GREEN, m_bGreen);
	DDX_Check(pDX, IDC_CHECK_RED, m_bRed);
}


BEGIN_MESSAGE_MAP(CDlgSelectColor, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgSelectColor::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgSelectColor 消息处理程序


void CDlgSelectColor::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	// 转换派生类
	// 控件状态到内存变量, UpdateData(TRUE)
	UpdateData(TRUE);
	((CHelloWorldView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bRed = this->m_bRed;
	((CHelloWorldView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bGreen = this->m_bGreen;
	((CHelloWorldView*)(((CMainFrame*)AfxGetMainWnd())->GetActiveView()))->m_bBlue = this->m_bBlue;

	// 刷新客户区的显示, API函数(全局)
	::InvalidateRect(AfxGetMainWnd()->GetSafeHwnd(), NULL, NULL);

	CDialogEx::OnOK();
}
