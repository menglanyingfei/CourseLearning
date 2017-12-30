
// LIXINGYANGDoc.h : CLIXINGYANGDoc 类的接口
//


#pragma once
#include "LIXINGYANGMyLine.h"

class CLIXINGYANGDoc : public CDocument
{
protected: // 仅从序列化创建
	CLIXINGYANGDoc();
	DECLARE_DYNCREATE(CLIXINGYANGDoc)

// 特性
public:

// 操作
public:
	void AddLine(CPoint pointStart, CPoint pointEnd); // 添加线段
	void OnDraw(CDC* pDC); // 对所有的线段进行绘制

	void OnUndo();
	void OnRedo();
	// 获取m_arrayLines的大小
	int GetArrayLinesSize();
	int GetArray2LinesSize();
	// 清空m_arrayLines
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
	virtual ~CLIXINGYANGDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CObArray m_arrayLines; // Object数组, 存放线段, 用于Undo操作的数组
	CObArray m_array2Lines; // 用于Redo操作的数组

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
