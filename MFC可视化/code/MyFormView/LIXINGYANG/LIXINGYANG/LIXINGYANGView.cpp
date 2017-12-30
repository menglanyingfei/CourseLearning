
// LIXINGYANGView.cpp : CLIXINGYANGView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "LIXINGYANG.h"
#endif

#include "LIXINGYANGDoc.h"
#include "LIXINGYANGView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLIXINGYANGView

IMPLEMENT_DYNCREATE(CLIXINGYANGView, CFormView)

BEGIN_MESSAGE_MAP(CLIXINGYANGView, CFormView)
	ON_COMMAND(ID_COLOR_DARKCOLOR, &CLIXINGYANGView::OnColorDarkcolor)
	ON_UPDATE_COMMAND_UI(ID_COLOR_DARKCOLOR, &CLIXINGYANGView::OnUpdateColorDarkcolor)
	ON_COMMAND(ID_COLOR_LIGHTCOLOR, &CLIXINGYANGView::OnColorLightcolor)
	ON_UPDATE_COMMAND_UI(ID_COLOR_LIGHTCOLOR, &CLIXINGYANGView::OnUpdateColorLightcolor)
	ON_BN_CLICKED(IDC_CHECK_BLUE, &CLIXINGYANGView::OnClickedCheckBlue)
	ON_BN_CLICKED(IDC_CHECK_GREEN, &CLIXINGYANGView::OnClickedCheckGreen)
	ON_BN_CLICKED(IDC_CHECK_RED, &CLIXINGYANGView::OnClickedCheckRed)
END_MESSAGE_MAP()

// CLIXINGYANGView ����/����

CLIXINGYANGView::CLIXINGYANGView()
	: CFormView(CLIXINGYANGView::IDD)
	, m_bBlue(FALSE)
	, m_bGreen(FALSE)
	, m_bRed(FALSE)
{
	// TODO:  �ڴ˴���ӹ������
	m_bRed = TRUE;
	m_bGreen = FALSE;
	m_bBlue = FALSE;
	m_enumIntensity = INTENSITY_LIGHT;
}

CLIXINGYANGView::~CLIXINGYANGView()
{
}

void CLIXINGYANGView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_BLUE, m_bBlue);
	DDX_Check(pDX, IDC_CHECK_GREEN, m_bGreen);
	DDX_Check(pDX, IDC_CHECK_RED, m_bRed);
	DDX_Control(pDX, IDC_STATIC_SAMPLE, m_ctrlSample);
}

BOOL CLIXINGYANGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CLIXINGYANGView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_ctrlSample.GetWindowRect(&m_rectSample);
	ScreenToClient(&m_rectSample);
	int nBorder = (m_rectSample.right - m_rectSample.left) / 8;
	m_rectSample.InflateRect(-nBorder, -nBorder);
	UpdateData(FALSE);
}


// CLIXINGYANGView ���

#ifdef _DEBUG
void CLIXINGYANGView::AssertValid() const
{
	CFormView::AssertValid();
}

void CLIXINGYANGView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CLIXINGYANGDoc* CLIXINGYANGView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLIXINGYANGDoc)));
	return (CLIXINGYANGDoc*)m_pDocument;
}
#endif //_DEBUG


// CLIXINGYANGView ��Ϣ�������


void CLIXINGYANGView::OnColorDarkcolor()
{
	// TODO:  �ڴ���������������
	m_enumIntensity = INTENSITY_DARK;
	CClientDC dc(this);
	OnPrepareDC(&dc);

	CRect rect = m_rectSample;
	dc.LPtoDP(&rect);
	InvalidateRect(&rect);   //ֻ����rect
}


void CLIXINGYANGView::OnUpdateColorDarkcolor(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->SetRadio(m_enumIntensity == INTENSITY_DARK);
}


void CLIXINGYANGView::OnColorLightcolor()
{
	// TODO:  �ڴ���������������
	m_enumIntensity = INTENSITY_LIGHT;
	CClientDC dc(this);
	OnPrepareDC(&dc);

	CRect rect = m_rectSample;
	dc.LPtoDP(&rect);
	InvalidateRect(&rect);   //ֻ����rect
}


void CLIXINGYANGView::OnUpdateColorLightcolor(CCmdUI *pCmdUI)
{
	// TODO:  �ڴ������������û����洦��������
	pCmdUI->SetRadio(m_enumIntensity == INTENSITY_LIGHT);
}


void CLIXINGYANGView::OnClickedCheckBlue()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CClientDC dc(this);
	OnPrepareDC(&dc);

	CRect rect = m_rectSample;
	dc.LPtoDP(&rect);
	InvalidateRect(&rect);
}


void CLIXINGYANGView::OnClickedCheckGreen()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CClientDC dc(this);
	OnPrepareDC(&dc);

	CRect rect = m_rectSample;
	dc.LPtoDP(&rect);
	InvalidateRect(&rect);
}


void CLIXINGYANGView::OnClickedCheckRed()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CClientDC dc(this);
	OnPrepareDC(&dc);

	CRect rect = m_rectSample;
	dc.LPtoDP(&rect);
	InvalidateRect(&rect);
}


void CLIXINGYANGView::OnDraw(CDC* pDC)
{
	// TODO:  �ڴ����ר�ô����/����û���
	COLORREF color = RGB(
		m_bRed ?
		(m_enumIntensity == INTENSITY_LIGHT ?
		255 : 128) : 0,
		m_bGreen ?
		(m_enumIntensity == INTENSITY_LIGHT ?
		255 : 128) : 0,
		m_bBlue ?
		(m_enumIntensity == INTENSITY_LIGHT ?
		255 : 128) : 0, );
	CBrush brush(color);
	pDC->FillRect(&m_rectSample, &brush);
}
