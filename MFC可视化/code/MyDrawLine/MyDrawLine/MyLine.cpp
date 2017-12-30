// MyLine.cpp : 实现文件
//
#include "stdafx.h"
#include "MyDrawLine.h"
#include "MyLine.h"

// CMyLine, 实现序列化声明
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
	// 一个矩形的四边分解为四条线段
	pDC->MoveTo(m_pointStart.x,m_pointStart.y);
	pDC->LineTo(m_pointStart.x,m_pointEnd.y);//左竖

	pDC->MoveTo(m_pointStart.x,m_pointEnd.y);
	pDC->LineTo(m_pointEnd.x,m_pointEnd.y);//下横

	pDC->MoveTo(m_pointStart.x,m_pointStart.y);
	pDC->LineTo(m_pointEnd.x,m_pointStart.y);//上横

	pDC->MoveTo(m_pointEnd.x,m_pointStart.y);
	pDC->LineTo(m_pointEnd.x,m_pointEnd.y);//右竖	
}

CMyLine::~CMyLine()
{
}

// CMyLine 成员函数, 实现序列化, 文件读写
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
