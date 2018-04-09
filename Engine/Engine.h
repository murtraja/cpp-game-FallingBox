#pragma once
#include "Renderer.h"
#include "GameWindow.h"
#include "GameFont.h"
#include "World.h"

#define ENGINE_FPS 30.f
#define ENGINE_FRAME_TIME 1000.f/30.f

class CEngine
{
	CEngine();
	bool m_engineRunning;
	float m_deltaTime;
	CGameWindow m_gameWindow;
	CRenderer m_renderer;
	CGameFont m_font;
	CWorld m_world;
public:
	static CEngine& GetInstance();
	~CEngine();
	bool Init();
	void Run();
	bool Destroy();
	void ProcessInputs();
	void UpdateGameState(double dt);
	void RenderWorld();
	CGameWindow& GetWindow();
	CRenderer& GetRenderer();
	CGameFont& GetFont();
	CWorld& GetWorld();
};

