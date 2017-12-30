
// LIXINGYANGDoc.cpp : CLIXINGYANGDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "LIXINGYANG.h"
#endif

#include "LIXINGYANGDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLIXINGYANGDoc

IMPLEMENT_DYNCREATE(CLIXINGYANGDoc, CDocument)

BEGIN_MESSAGE_MAP(CLIXINGYANGDoc, CDocument)
END_MESSAGE_MAP()


// CLIXINGYANGDoc ����/����

CLIXINGYANGDoc::CLIXINGYANGDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CLIXINGYANGDoc::~CLIXINGYANGDoc()
{
}

BOOL CLIXINGYANGDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CLIXINGYANGDoc ���л�

void CLIXINGYANGDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{

		// TODO: �ڴ���Ӵ洢����
		m_arrayLines.Serialize(ar);
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		m_arrayLines.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CLIXINGYANGDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CLIXINGYANGDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CLIXINGYANGDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CLIXINGYANGDoc ���

#ifdef _DEBUG
void CLIXINGYANGDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLIXINGYANGDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CLIXINGYANGDoc ����
void CLIXINGYANGDoc::AddLine(CPoint pointStart, CPoint pointEnd) 
{
	LIXINGYANGMyLine* pMyLine = new LIXINGYANGMyLine(pointStart, pointEnd);
	
	m_arrayLines.Add(pMyLine); //�����߶μ���������

	// �ĵ��������ݷ����˱仯
	SetModifiedFlag();
}

void CLIXINGYANGDoc::OnDraw(CDC* pDC) 
{
	// ����ÿ���߶�: ����
	for (int i = 0; i < m_arrayLines.GetSize(); i++) {
		((LIXINGYANGMyLine*)m_arrayLines.GetAt(i))->OnDraw(pDC);
	}
}

void CLIXINGYANGDoc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class
	/*
	int index;
	index = m_arrayLines.GetSize();

	while (index) {
		// deleteÿһ���߶�
		delete m_arrayLines.GetAt(--index);
	}

	m_arrayLines.RemoveAll();
	*/

	ClearArrayLines();
	ClearArray2Lines();

	CDocument::DeleteContents();
}

// 11.13
void CLIXINGYANGDoc::OnUndo() {
	int index;

	index = m_arrayLines.GetUpperBound();
	if (index >= 0) {
		m_array2Lines.Add(m_arrayLines.GetAt(index));
		m_arrayLines.RemoveAt(index);
		UpdateAllViews(NULL);

		// ���鷢���˱仯(�ĵ������ݷ����˱仯)
		SetModifiedFlag();
	}
}

void CLIXINGYANGDoc::OnRedo() {
	int index;

	index = m_array2Lines.GetUpperBound();
	if (index >= 0) {
		m_arrayLines.Add(m_array2Lines.GetAt(index));
		m_array2Lines.RemoveAt(index);
		UpdateAllViews(NULL);

		// ���鷢���˱仯(�ĵ������ݷ����˱仯), ��ʾ�û���������
		SetModifiedFlag();
	}
}

int CLIXINGYANGDoc::GetArrayLinesSize() {
	return m_arrayLines.GetSize();
}

int CLIXINGYANGDoc::GetArray2LinesSize() {
	return m_array2Lines.GetSize();
}

void CLIXINGYANGDoc::ClearArrayLines() {
	for (int i = 0; i < m_arrayLines.GetSize(); i++) {
		delete m_arrayLines.GetAt(i);
	}

	m_arrayLines.RemoveAll();
}

void CLIXINGYANGDoc::ClearArray2Lines() {
	for (int i = 0; i < m_array2Lines.GetSize(); i++) {
		delete m_array2Lines.GetAt(i);
	}

	m_array2Lines.RemoveAll();
}








