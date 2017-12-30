#pragma once
#include "afx.h"
class LIXINGYANGMyLine :
	public CObject
{
public:
	LIXINGYANGMyLine(void);
	LIXINGYANGMyLine(CPoint pointStart, CPoint pointEnd);
	virtual ~LIXINGYANGMyLine(void);

	void OnDraw(CDC* pDC);

protected:
	CPoint m_pointStart;
	CPoint m_pointEnd;

	DECLARE_SERIAL(LIXINGYANGMyLine)

public:
	virtual void Serialize(CArchive& ar);
};

