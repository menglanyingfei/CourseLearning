
// MyDrawLineDoc.h : CMyDrawLineDoc 类的接口
//


#pragma once
#include "MyLine.h"

class CMyDrawLineDoc : public CDocument
{
protected: // 仅从序列化创建
	CMyDrawLineDoc();
	DECLARE_DYNCREATE(CMyDrawLineDoc)
	CObArray m_arrayLines;
	CObArray m_array2Lines;
// 特性
public:

// 操作
public:
	void AddLine(CPoint pointStart,CPoint pointEnd);
	void OnDraw(CDC* pDC);
	void OnUndo();
	void OnRedo();
	int GetArrayLinesSize();
	int GetArray2LinesSize();
	void ClearArrayLines();
	void ClearArray2Lines();

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CMyDrawLineDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
};
