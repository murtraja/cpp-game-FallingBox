#pragma once

#include "Engine_pch.h"
#include "GameObject.h"
#include "PhyEngine.h"

class CWorld
{
	std::vector<CGameObject*> m_objects;
	CPhyEngine m_phyEngine;
public:
	CWorld();
	~CWorld();
	bool Init();
	bool Update(double dt);
	bool Render();
	bool Register(CGameObject* object);
	bool Unregister(CGameObject* object);
	CGameObject* Query(std::string);
};

