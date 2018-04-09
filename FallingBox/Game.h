#pragma once

#include "Box.h"

class CGame
{
	CBox m_box;
public:
	CGame();
	~CGame();
	bool Init();
	void Start();
	bool Destroy();
};

