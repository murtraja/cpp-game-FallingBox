#include "Engine_pch.h"
#include "GameObject.h"
#include "Engine.h"


void CGameObject::MakeDynamicBox(int width, int height)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = CPhyEngine::ToPhyPosition(m_position);
	CEngine::GetPhyEngine().CreateBody(bodyDef);
}

CGameObject::CGameObject()
	: m_phyBody(nullptr)
	, m_position(0,0)
	, m_id("")
{
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
	m_texture.Render(m_position);
	return true;
}

bool CGameObject::Render(int width, int height)
{
	SDL_Rect objectViewPort = { m_position.m_x, m_position.m_y, width, height };
	SDL_RenderSetViewport(CEngine::GetInstance().GetRenderer().GetSDLRenderer(), &objectViewPort);
	m_texture.Render(m_position);
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
	m_position.Set(x, y);
}
