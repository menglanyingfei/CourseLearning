
// LIXINGYANGDoc.cpp : CLIXINGYANGDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CLIXINGYANGDoc 构造/析构

CLIXINGYANGDoc::CLIXINGYANGDoc()
{
	// TODO: 在此添加一次性构造代码

}

CLIXINGYANGDoc::~CLIXINGYANGDoc()
{
}

BOOL CLIXINGYANGDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CLIXINGYANGDoc 序列化

void CLIXINGYANGDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{

		// TODO: 在此添加存储代码
		m_arrayLines.Serialize(ar);
	}
	else
	{
		// TODO: 在此添加加载代码
		m_arrayLines.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CLIXINGYANGDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CLIXINGYANGDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CLIXINGYANGDoc 诊断

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


// CLIXINGYANGDoc 命令
void CLIXINGYANGDoc::AddLine(CPoint pointStart, CPoint pointEnd) 
{
	LIXINGYANGMyLine* pMyLine = new LIXINGYANGMyLine(pointStart, pointEnd);
	
	m_arrayLines.Add(pMyLine); //将该线段加入数组中

	// 文档类中数据发生了变化
	SetModifiedFlag();
}

void CLIXINGYANGDoc::OnDraw(CDC* pDC) 
{
	// 遍历每条线段: 绘制
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
		// delete每一条线段
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

		// 数组发生了变化(文档类数据发生了变化)
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

		// 数组发生了变化(文档类数据发生了变化), 提示用户保存数据
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








