#include "Engine_pch.h"
#include "Engine.h"
#include "GameWindow.h"
#include "Renderer.h"
#include "GameFont.h"

CEngine::CEngine()
	: m_engineRunning(false)
	, m_deltaTime(0.f)
{
}


CEngine& CEngine::GetInstance()
{
	static CEngine engine;
	return engine;
}

CEngine::~CEngine()
{
}

bool CEngine::Init()
{
	printf("Engine Init\n");

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	
	if (!m_gameWindow.Init())
	{
		return false;
	}

	if(!m_renderer.Init())
	{
		return false;
	}

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	
	return true;
}

void CEngine::Run()
{
	// the main game loop is here
	m_engineRunning = true;
	unsigned long lastFrameStartTime = SDL_GetTicks();
	while (m_engineRunning)
	{
		unsigned long currentFrameStartTime = SDL_GetTicks();
		unsigned long elapsedTime = currentFrameStartTime - lastFrameStartTime;
		ProcessInputs();
		UpdateGameState((double)elapsedTime);
		RenderWorld();
		lastFrameStartTime = currentFrameStartTime;
		if (m_deltaTime < ENGINE_FRAME_TIME)
		{
			SDL_Delay(ENGINE_FRAME_TIME - m_deltaTime);
		}
	}
}

bool CEngine::Destroy()
{
	printf("Engine destroy\n");

	if (!m_renderer.Destroy())
	{
		return false;
	}

	if (!m_gameWindow.Destroy())
	{
		return false;
	}

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return true;
}

void CEngine::ProcessInputs()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			m_engineRunning = false;
		}
	}
}

void CEngine::UpdateGameState(double dt)
{
	m_world.Update(dt);
}

void CEngine::RenderWorld()
{
	m_renderer.Clear();
	m_world.Render();
	m_renderer.Draw();
}

CGameWindow& CEngine::GetWindow()
{
	return m_gameWindow;
}

CRenderer& CEngine::GetRenderer()
{
	return m_renderer;
}

CGameFont& CEngine::GetFont()
{
	return m_font;
}

CWorld& CEngine::GetWorld()
{
	return m_world;
}
