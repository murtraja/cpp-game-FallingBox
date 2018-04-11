#include "Engine_pch.h"
#include "World.h"


CWorld::CWorld()
{
}


CWorld::~CWorld()
{
}

bool CWorld::Update(double dt)
{
	for (auto it = m_objects.begin(); it != m_objects.end(); ++it)
	{
		(*it)->Update(dt);
	}
	return true;
}

bool CWorld::Render()
{
	for (auto it = m_objects.begin(); it != m_objects.end(); ++it)
	{
		(*it)->Render();
	}
	return true;
}

bool CWorld::Register(CGameObject* object)
{
	if (!object)
	{
		printf("Unable to register a null game object\n");
		return false;
	}

	if (!object->HasValidId())
	{
		printf("Unable to register a game object with invalid id\n");
		return false;
	}

	m_objects.push_back(object);
	return true;
}

bool CWorld::Unregister(CGameObject* object)
{
	if (!object)
	{
		printf("Unable to unregister a null game object\n");
		return false;
	}

	if (m_objects.empty())
	{
		printf("No game objects registered\n");
		return false;
	}

	for (auto it = m_objects.begin(); it!=m_objects.end(); ++it)
	{
		if ((*it)->GetId() == object->GetId())
		{
			m_objects.erase(it);
			return true;
		}
	}
	return false;
}

CGameObject* CWorld::Query(std::string id)
{
	auto it = std::find_if(m_objects.begin(), m_objects.end(), 
		[id](CGameObject* obj) -> bool { return id == obj->GetId(); });

	if (it != m_objects.end())
	{
		return *it;
	}
	return nullptr;
}
