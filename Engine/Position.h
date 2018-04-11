#pragma once

#include "Engine_pch.h"

class CPosition
{
public:
	int m_x, m_y;
	CPosition();
	CPosition(int x, int y);
	~CPosition();
	void Set(int x, int y);
	b2Vec2 ToBox2D();
};

