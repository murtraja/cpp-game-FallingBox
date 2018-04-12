#pragma once

#include "Engine_pch.h"

class CPosition
{
public:
	float m_x, m_y;
	CPosition();
	CPosition(float x, float y);
	CPosition(const b2Vec2 pos);
	~CPosition();
	void Set(float x, float y);
	b2Vec2 ToBox2D();
	b2Vec2 operator*(const float scalar);
	CPosition& operator *=(const float scalar);
};

