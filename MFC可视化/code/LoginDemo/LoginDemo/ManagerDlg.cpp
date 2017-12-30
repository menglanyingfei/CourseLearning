// ManagerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LoginDemo.h"
#include "ManagerDlg.h"
#include "afxdialogex.h"


// CManagerDlg 对话框

IMPLEMENT_DYNAMIC(CManagerDlg, CDialogEx)

CManagerDlg::CManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManagerDlg::IDD, pParent)
{

}

CManagerDlg::~CManagerDlg()
{
}

void CManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CManagerDlg, CDialogEx)
END_MESSAGE_MAP()


// CManagerDlg 消息处理程序
