
// MyDrawLineDoc.cpp : CMyDrawLineDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MyDrawLine.h"
#endif

#include "MyDrawLineDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMyDrawLineDoc

IMPLEMENT_DYNCREATE(CMyDrawLineDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyDrawLineDoc, CDocument)
END_MESSAGE_MAP()


// CMyDrawLineDoc 构造/析构

CMyDrawLineDoc::CMyDrawLineDoc()
{
	// TODO: 在此添加一次性构造代码

}

CMyDrawLineDoc::~CMyDrawLineDoc()
{
	ClearArrayLines();
	ClearArray2Lines();
}

BOOL CMyDrawLineDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CMyDrawLineDoc 序列化

void CMyDrawLineDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		m_arrayLines.Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
		m_arrayLines.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMyDrawLineDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CMyDrawLineDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMyDrawLineDoc::SetSearchContent(const CString& value)
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

// CMyDrawLineDoc 诊断

#ifdef _DEBUG
void CMyDrawLineDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyDrawLineDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMyDrawLineDoc 命令


void CMyDrawLineDoc::DeleteContents()
{
	// TODO: 在此添加专用代码和/或调用基类
	int index;

	index = m_arrayLines.GetSize();

	while (index)
		delete m_arrayLines.GetAt(--index);

	m_arrayLines.RemoveAll();
	CDocument::DeleteContents();
}

void CMyDrawLineDoc::OnUndo()
{
int index;

	index = m_arrayLines.GetUpperBound();
	if (index >= 0) {
		m_array2Lines.Add(m_arrayLines.GetAt(index));
		m_arrayLines.RemoveAt(index);
		UpdateAllViews(NULL);
		SetModifiedFlag();
	}
}

void CMyDrawLineDoc::OnRedo()
{
	int index;

	index = m_array2Lines.GetUpperBound();
	if (index >= 0) {
		m_arrayLines.Add(m_array2Lines.GetAt(index));
		m_array2Lines.RemoveAt(index);
		UpdateAllViews(NULL);
		SetModifiedFlag();
	}
}

int CMyDrawLineDoc::GetArrayLinesSize()
{
	return m_arrayLines.GetSize();
}

int CMyDrawLineDoc::GetArray2LinesSize()
{
	return m_array2Lines.GetSize();
}

void CMyDrawLineDoc::ClearArrayLines()
{
	int i;

	for (i=0;i<m_arrayLines.GetSize();i++) {
		delete m_arrayLines.GetAt(i);
		m_arrayLines.RemoveAt(i);
	}
}

void CMyDrawLineDoc::ClearArray2Lines()
{
	int i;

	for (i=0;i<m_array2Lines.GetSize();i++) {
		delete m_array2Lines.GetAt(i);
		m_array2Lines.RemoveAt(i);
	}
}

void CMyDrawLineDoc::AddLine(CPoint pointStart,CPoint pointEnd)
{
	CMyLine* pMyLine = new CMyLine(pointStart,pointEnd);
	m_arrayLines.Add(pMyLine);
	SetModifiedFlag();
}

void CMyDrawLineDoc::OnDraw(CDC* pDC)
{
	int i;

	for (i=0;i<m_arrayLines.GetSize();i++) {
		((CMyLine*)m_arrayLines.GetAt(i))->OnDraw(pDC);	
	}
}
