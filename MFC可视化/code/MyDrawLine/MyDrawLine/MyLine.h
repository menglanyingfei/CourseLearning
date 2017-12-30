#pragma once

// CMyLine Í·ÎÄ¼þ
class CMyLine : public CObject
{
public:
	CMyLine();
	CMyLine(CPoint pointStart,CPoint pointEnd);
	virtual ~CMyLine();

	void OnDraw(CDC *pDC);
protected:
	CPoint m_pointStart;
	CPoint m_pointEnd;
	DECLARE_SERIAL(CMyLine)
public:
	virtual void Serialize(CArchive& ar);
};


