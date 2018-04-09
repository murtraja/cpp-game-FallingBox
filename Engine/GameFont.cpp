#include "Engine_pch.h"
#include "GameFont.h"


CGameFont::CGameFont()
{
}


CGameFont::~CGameFont()
{
}

bool CGameFont::Init()
{
	m_sdlFont = TTF_OpenFont("", 28);
	if (!m_sdlFont)
	{
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	return true;
}

bool CGameFont::Destroy()
{
	TTF_CloseFont(m_sdlFont);
	m_sdlFont = nullptr;
	return true;
}

TTF_Font* CGameFont::GetSDLFont()
{
	return m_sdlFont;
}
