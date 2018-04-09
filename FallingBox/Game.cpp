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
	CEngine::GetInstance().GetWorld().Register(&m_box);

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
