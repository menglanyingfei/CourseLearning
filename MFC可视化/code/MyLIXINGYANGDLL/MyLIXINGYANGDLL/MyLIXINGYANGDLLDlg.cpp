
// MyLIXINGYANGDLLDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMyLIXINGYANGDLLDlg �Ի���



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


// CMyLIXINGYANGDLLDlg ��Ϣ�������

BOOL CMyLIXINGYANGDLLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMyLIXINGYANGDLLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMyLIXINGYANGDLLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


typedef double(*FactorialFunc)(int);
void CMyLIXINGYANGDLLDlg::OnClickedButtonDcall()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

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
