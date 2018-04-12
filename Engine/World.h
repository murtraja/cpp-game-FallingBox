#pragma once

#include "Engine_pch.h"
#include "GameObject.h"
#include "PhyEngine.h"

class CWorld
{
	std::vector<CGameObject*> m_objects;
public:
	CWorld();
	~CWorld();
	bool Init();
	bool Update(float dt);
	bool Render();
	bool Register(CGameObject* object);
	bool Unregister(CGameObject* object);
	CGameObject* Query(std::string);
};

