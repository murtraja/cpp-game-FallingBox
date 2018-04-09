#include "Engine_pch.h"
#include "GameObject.h"


CGameObject::CGameObject()
{
	m_id = "";
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
	m_texture.render(m_x, m_y);
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
