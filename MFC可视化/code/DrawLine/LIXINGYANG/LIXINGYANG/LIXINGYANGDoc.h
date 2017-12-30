
// LIXINGYANGDoc.h : CLIXINGYANGDoc ��Ľӿ�
//


#pragma once
#include "LIXINGYANGMyLine.h"

class CLIXINGYANGDoc : public CDocument
{
protected: // �������л�����
	CLIXINGYANGDoc();
	DECLARE_DYNCREATE(CLIXINGYANGDoc)

// ����
public:

// ����
public:
	void AddLine(CPoint pointStart, CPoint pointEnd); // ����߶�
	void OnDraw(CDC* pDC); // �����е��߶ν��л���

	void OnUndo();
	void OnRedo();
	// ��ȡm_arrayLines�Ĵ�С
	int GetArrayLinesSize();
	int GetArray2LinesSize();
	// ���m_arrayLines
	void ClearArrayLines();
	void ClearArray2Lines();

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CLIXINGYANGDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CObArray m_arrayLines; // Object����, ����߶�, ����Undo����������
	CObArray m_array2Lines; // ����Redo����������

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
};
