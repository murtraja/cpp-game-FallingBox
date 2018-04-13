#pragma once
#include "Renderer.h"
#include "GameWindow.h"
#include "GameFont.h"
#include "World.h"
#include "InputManager.h"

#define ENGINE_FPS 30.f
#define ENGINE_FRAME_TIME 1000.f/ENGINE_FPS

class CEngine
{
	CEngine();
	bool m_engineRunning;
	float m_deltaTime;
	CGameWindow m_gameWindow;
	CRenderer m_renderer;
	CGameFont m_font;
	CWorld m_world;
	CPhyEngine m_phyEngine;
	CInputManager m_inputManager;
public:
	static CEngine& GetInstance();
	~CEngine();
	bool Init();
	void Run();
	bool Destroy();
	void ProcessInputs();
	void UpdateGameState(float dt);
	void RenderWorld();
	void RequestShutdown();
	CGameWindow& GetWindow();
	CRenderer& GetRenderer();
	CGameFont& GetFont();
	CWorld& GetWorld();
	CPhyEngine& GetPhyEngine();
	CInputManager& GetInputManager();
};

