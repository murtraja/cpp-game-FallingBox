#include "Engine_pch.h"
#include "Position.h"


CPosition::CPosition()
	: m_x(0)
	, m_y(0)
{
}

CPosition::CPosition(int x, int y)
	: m_x(x)
	, m_y(y)
{
}

CPosition::~CPosition()
{
}

void CPosition::Set(int x, int y)
{
	m_x = x;
	m_y = y;
}

b2Vec2 CPosition::ToBox2D()
{
	return b2Vec2((float)m_x, (float)m_y);
}