#include "Engine_pch.h"
#include "GameWindow.h"


CGameWindow::CGameWindow()
	: m_width(640)
	, m_height(480)
	, m_sdlWindow(nullptr)
{
}


CGameWindow::~CGameWindow()
{
}

void CGameWindow::SetDimension(int width, int height)
{
	m_width = width;
	m_height = height;
}

bool CGameWindow::Init()
{
	m_sdlWindow = SDL_CreateWindow("Falling Box", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		m_width, m_height, SDL_WINDOW_SHOWN);
	if (!m_sdlWindow)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	return true;
}

SDL_Window* CGameWindow::GetSDLWindow()
{
	return m_sdlWindow;
}

bool CGameWindow::Destroy()
{
	SDL_DestroyWindow(m_sdlWindow);
	m_sdlWindow = nullptr;
	return true;
}
