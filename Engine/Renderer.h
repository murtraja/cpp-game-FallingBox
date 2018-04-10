#pragma once

#include "Engine_pch.h"

class CRenderer
{
	SDL_Renderer* m_sdlRenderer;
public:
	CRenderer();
	~CRenderer();
	bool Init();
	bool Destroy();
	SDL_Renderer* GetSDLRenderer();
	void Draw();
	void Clear();
};

