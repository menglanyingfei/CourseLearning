#include "StdAfx.h"
#include "LIXINGYANGMyLine.h"

// �������л�
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

	// ˼·: һ�����ε��ı߷ֽ�Ϊ�����߶�
	pDC->MoveTo(m_pointStart.x, m_pointStart.y);
	pDC->LineTo(m_pointStart.x, m_pointEnd.y);//����

	pDC->MoveTo(m_pointStart.x, m_pointEnd.y);
	pDC->LineTo(m_pointEnd.x, m_pointEnd.y);//�º�

	pDC->MoveTo(m_pointStart.x, m_pointStart.y);
	pDC->LineTo(m_pointEnd.x, m_pointStart.y);//�Ϻ�

	pDC->MoveTo(m_pointEnd.x, m_pointStart.y);
	pDC->LineTo(m_pointEnd.x, m_pointEnd.y);//����
}

LIXINGYANGMyLine::~LIXINGYANGMyLine(void)
{
}

void LIXINGYANGMyLine::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		// ���л� - д
		ar << m_pointStart << m_pointEnd;
	}
	else
	{	// loading code ��
		ar >> m_pointStart >> m_pointEnd;

	}
}
