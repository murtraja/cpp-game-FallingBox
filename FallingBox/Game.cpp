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

	CEngine::GetInstance().GetInputManager().RegisterInputCallback(this);
/*
	m_box.SetId("box");
	m_box.SetDimension(50, 50);
	m_box.SetTexture("texture/crate_2.png");
	m_box.SetPosition(GAME_WINDOW_WIDTH / 2 , 0);
	m_box.MakeDynamicBox();
	CEngine::GetInstance().GetWorld().Register(&m_box);*/

	
	m_ground.SetId("ground");
	m_ground.SetDimension(GAME_WINDOW_WIDTH/4, GAME_WINDOW_HEIGHT / 8);
	m_ground.SetTexture("texture/ground_1.jpg");
	m_ground.SetPosition(GAME_WINDOW_WIDTH/2, GAME_WINDOW_HEIGHT / 1.5);
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

void CGame::SpawnBox(int x, int y)
{
	CBox* box = new CBox();
	int boxesSpawned = m_boxes.size();
	char boxNo[2];
	snprintf(boxNo, 2, "%02d", boxesSpawned);
	box->SetId("box" + std::string(boxNo));
	box->SetDimension(50, 50);
	box->SetTexture("texture/crate_2.png");
	box->SetPosition(x,y);
	box->MakeDynamicBox();
	CEngine::GetInstance().GetWorld().Register(box);
	m_boxes.push_back(box);
}

void CGame::OnInputEvent(std::vector<InputInfo> infos)
{
	for (auto itr = infos.begin(); itr != infos.end(); ++itr)
	{
		InputInfo info = *itr;
		switch (info.m_inputType)
		{
		case EInputType_Keyboard:

			break;

		case EInputType_Mouse:
			int x = info.m_inputInfoData.m_inputInfoMouse.m_x;
			int y = info.m_inputInfoData.m_inputInfoMouse.m_y;
			SpawnBox(x, y);
			break;
		}
	}
}
