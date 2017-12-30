
// MyLIXINGYANGDLLDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MyLIXINGYANGDLL.h"
#include "MyLIXINGYANGDLLDlg.h"
#include "afxdialogex.h"
#include "MyLIXINGYANGFactorial\MyLIXINGYANGFactorial.h"
#pragma comment(lib,"MyLIXINGYANGFactorial\\MyLIXINGYANGFactorial.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyLIXINGYANGDLLDlg 对话框



CMyLIXINGYANGDLLDlg::CMyLIXINGYANGDLLDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyLIXINGYANGDLLDlg::IDD, pParent)
	, m_nNum(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyLIXINGYANGDLLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NUM, m_nNum);
}

BEGIN_MESSAGE_MAP(CMyLIXINGYANGDLLDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DCALL, &CMyLIXINGYANGDLLDlg::OnClickedButtonDcall)
	ON_BN_CLICKED(IDC_BUTTON_SCALL, &CMyLIXINGYANGDLLDlg::OnClickedButtonScall)
	ON_BN_CLICKED(IDC_BUTTON_DLL_SORT, &CMyLIXINGYANGDLLDlg::OnClickedButtonDllSort)
END_MESSAGE_MAP()


// CMyLIXINGYANGDLLDlg 消息处理程序

BOOL CMyLIXINGYANGDLLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMyLIXINGYANGDLLDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMyLIXINGYANGDLLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMyLIXINGYANGDLLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


typedef double(*FactorialFunc)(int);
void CMyLIXINGYANGDLLDlg::OnClickedButtonDcall()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	HINSTANCE hInstLib = LoadLibrary(L"MyLIXINGYANGFactorial\\MyLIXINGYANGFactorial.dll");
	if (hInstLib == NULL)
		FreeLibrary(hInstLib);
	FactorialFunc factorial = (FactorialFunc)GetProcAddress(hInstLib, "factorial");
	if (factorial == NULL)
		FreeLibrary(hInstLib);

	CString str;
	double result;
	result = factorial(m_nNum);
	str.Format(L"%lf", result);
	MessageBox(str);
	FreeLibrary(hInstLib);
}


void CMyLIXINGYANGDLLDlg::OnClickedButtonScall()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CString str;
	double result;
	result = factorial(m_nNum);
	str.Format(L"%lf", result);
	MessageBox(str);
}

typedef void(*FactorialFunc1)(double* a, double len);
void CMyLIXINGYANGDLLDlg::OnClickedButtonDllSort()
{
	// TODO:  在此添加控件通知处理程序代码

	//MessageBox(L"Hello!");
	UpdateData(TRUE);
	HINSTANCE hInstLib = LoadLibrary(L"MyLIXINGYANGFactorial\\MyLIXINGYANGFactorial.dll");
	if (hInstLib == NULL)
		FreeLibrary(hInstLib);
	FactorialFunc1 factorial = (FactorialFunc1)GetProcAddress(hInstLib, "sort");
	if (factorial == NULL)
		FreeLibrary(hInstLib);

	CString str;
	
	double a[6] = {1, 5, 4, 3, 6, 2};
	
	sort(a, 6);
	
	str.Format(L"%lf %lf %lf %lf %lf %lf", a[0], a[1], a[2], a[3], a[4], a[5]);
	MessageBox(str);
	FreeLibrary(hInstLib);
}
