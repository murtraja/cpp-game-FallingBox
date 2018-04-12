#include "Engine_pch.h"
#include "Renderer.h"
#include "Engine.h"
#include "GameWindow.h"

CRenderer::CRenderer()
{
}


CRenderer::~CRenderer()
{
}

bool CRenderer::Init()
{
	m_sdlRenderer = SDL_CreateRenderer(CEngine::GetInstance().GetWindow().GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_sdlRenderer)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	SDL_SetRenderDrawColor(m_sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	return true;
}

bool CRenderer::Destroy()
{
	SDL_DestroyRenderer(m_sdlRenderer);
	m_sdlRenderer = nullptr;
	return true;
}

SDL_Renderer* CRenderer::GetSDLRenderer()
{
	return m_sdlRenderer;
}

void CRenderer::Draw()
{
	SDL_RenderPresent(m_sdlRenderer);
}

void CRenderer::Clear()
{
	SDL_RenderClear(m_sdlRenderer);
}
