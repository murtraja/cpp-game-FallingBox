#include "stdafx.h"
#include "Game.h"
#include "Engine/Engine.h"
#include "Box.h"

CGame::CGame()
{
}


CGame::~CGame()
{
}

bool CGame::Init()
{
	printf("Game init\n");
	if (!CEngine::GetInstance().Init())
	{
		printf("Engine failed to initialize\n");
		return false;
	}

	m_box.SetId("box");
	m_box.SetDimension(50, 50);
	m_box.SetTexture("texture/crate_2.png");
	m_box.SetPosition(GAME_WINDOW_WIDTH / 2 - 27, 0);
	m_box.MakeDynamicBox();
	CEngine::GetInstance().GetWorld().Register(&m_box);

	
	m_ground.SetId("ground");
	m_ground.SetDimension(GAME_WINDOW_WIDTH/4, GAME_WINDOW_HEIGHT / 8);
	m_ground.SetTexture("texture/ground_1.jpg");
	m_ground.SetPosition(GAME_WINDOW_WIDTH/2, GAME_WINDOW_HEIGHT / 4);
	m_ground.MakeStaticBox();
	CEngine::GetInstance().GetWorld().Register(&m_ground);
	

	return true;
}

void CGame::Start()
{
	printf("Game start\n");
	// let the looping begin!
	
	CEngine::GetInstance().Run();
}

bool CGame::Destroy()
{
	printf("Game destroy\n");
	return true;
}
