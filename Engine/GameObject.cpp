#include "Engine_pch.h"
#include "GameObject.h"
#include "Engine.h"


CGameObject::CGameObject()
{
	m_id = "";
	SetPosition(0, 0);
}


CGameObject::~CGameObject()
{
}

bool CGameObject::Init()
{
	return true;
}

bool CGameObject::Update(double dt)
{
	return true;
}

bool CGameObject::Render()
{
	m_texture.Render(m_x, m_y);
	return true;
}

bool CGameObject::Render(int width, int height)
{
	SDL_Rect objectViewPort = { m_x, m_y, width, height };
	SDL_RenderSetViewport(CEngine::GetInstance().GetRenderer().GetSDLRenderer(), &objectViewPort);
	m_texture.Render(m_x, m_y);
	return true;
}

bool CGameObject::Destroy()
{
	return true;
}

bool CGameObject::HasValidId()
{
	bool isValid = (m_id != "");
	return isValid;
}

std::string CGameObject::GetId()
{
	return m_id;
}

void CGameObject::SetId(std::string id)
{
	m_id = id;
}

void CGameObject::SetPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}
