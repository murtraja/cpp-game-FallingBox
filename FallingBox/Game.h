#pragma once

#include "Box.h"

class CGame
{
	CBox m_box;
	CBox m_ground;
public:
	CGame();
	~CGame();
	bool Init();
	void Start();
	bool Destroy();
};

