#include "Engine_pch.h"
#include "Position.h"


CPosition::CPosition()
	: m_x(0)
	, m_y(0)
{
}

CPosition::CPosition(float x, float y)
	: m_x(x)
	, m_y(y)
{
}

CPosition::CPosition(const b2Vec2 pos)
{
	Set(pos.x, pos.y);
}

CPosition::~CPosition()
{
}

void CPosition::Set(float x, float y)
{
	m_x = x;
	m_y = y;
}

b2Vec2 CPosition::ToBox2D()
{
	return b2Vec2(m_x, m_y);
}

b2Vec2 CPosition::operator*(const float scalar)
{
	return b2Vec2(m_x*scalar, m_y*scalar);
}

CPosition& CPosition::operator*=(const float scalar)
{
	m_x *= scalar;
	m_y *= scalar;
	return *this;
}

