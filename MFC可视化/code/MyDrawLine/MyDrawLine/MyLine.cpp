// MyLine.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "MyDrawLine.h"
#include "MyLine.h"

// CMyLine, ʵ�����л�����
IMPLEMENT_SERIAL(CMyLine,CObject,1)
CMyLine::CMyLine()
{
}

CMyLine::CMyLine(CPoint pointStart,CPoint pointEnd)
{
	m_pointStart = pointStart;
	m_pointEnd = pointEnd;
}

void CMyLine::OnDraw(CDC *pDC)
{
	// һ�����ε��ı߷ֽ�Ϊ�����߶�
	pDC->MoveTo(m_pointStart.x,m_pointStart.y);
	pDC->LineTo(m_pointStart.x,m_pointEnd.y);//����

	pDC->MoveTo(m_pointStart.x,m_pointEnd.y);
	pDC->LineTo(m_pointEnd.x,m_pointEnd.y);//�º�

	pDC->MoveTo(m_pointStart.x,m_pointStart.y);
	pDC->LineTo(m_pointEnd.x,m_pointStart.y);//�Ϻ�

	pDC->MoveTo(m_pointEnd.x,m_pointStart.y);
	pDC->LineTo(m_pointEnd.x,m_pointEnd.y);//����	
}

CMyLine::~CMyLine()
{
}

// CMyLine ��Ա����, ʵ�����л�, �ļ���д
void CMyLine::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	
		ar << m_pointStart << m_pointEnd;
	}
	else
	{	
		ar >> m_pointStart >> m_pointEnd;
	}
}
