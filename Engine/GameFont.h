#pragma once

#include "Engine_pch.h"

class CGameFont
{
	TTF_Font* m_sdlFont;
public:
	CGameFont();
	~CGameFont();
	bool Init();
	bool Destroy();
	TTF_Font* GetSDLFont();
};

