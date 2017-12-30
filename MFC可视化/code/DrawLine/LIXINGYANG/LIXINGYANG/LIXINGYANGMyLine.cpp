#include "StdAfx.h"
#include "LIXINGYANGMyLine.h"

// 对象序列化
IMPLEMENT_SERIAL(LIXINGYANGMyLine, CObject, 1)

LIXINGYANGMyLine::LIXINGYANGMyLine(void)
{
}

LIXINGYANGMyLine::LIXINGYANGMyLine(CPoint pointStart, CPoint pointEnd)
{
	m_pointStart = pointStart;
	m_pointEnd = pointEnd;
}

void LIXINGYANGMyLine::OnDraw(CDC* pDC) 
{
	//pDC->MoveTo(m_pointStart);
	//pDC->LineTo(m_pointEnd);

	// 思路: 一个矩形的四边分解为四条线段
	pDC->MoveTo(m_pointStart.x, m_pointStart.y);
	pDC->LineTo(m_pointStart.x, m_pointEnd.y);//左竖

	pDC->MoveTo(m_pointStart.x, m_pointEnd.y);
	pDC->LineTo(m_pointEnd.x, m_pointEnd.y);//下横

	pDC->MoveTo(m_pointStart.x, m_pointStart.y);
	pDC->LineTo(m_pointEnd.x, m_pointStart.y);//上横

	pDC->MoveTo(m_pointEnd.x, m_pointStart.y);
	pDC->LineTo(m_pointEnd.x, m_pointEnd.y);//右竖
}

LIXINGYANGMyLine::~LIXINGYANGMyLine(void)
{
}

void LIXINGYANGMyLine::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		// 序列化 - 写
		ar << m_pointStart << m_pointEnd;
	}
	else
	{	// loading code 读
		ar >> m_pointStart >> m_pointEnd;

	}
}
