#include "stdafx.h"
#include "Box.h"


CBox::CBox()
{
}


CBox::~CBox()
{
}

bool CBox::Init()
{	
	return CGameObject::Init();
}

bool CBox::Update(float dt)
{
	return CGameObject::Update(dt);
}

bool CBox::Render()
{
	CGameObject::Render(m_width, m_height);
	return true;
}

bool CBox::Destroy()
{
	return CGameObject::Destroy();
}

bool CBox::SetTexture(std::string path)
{
	bool loaded = m_texture.LoadFromFile(path);
	m_texture.SetDimension(m_width, m_height);
	return loaded;
}

void CBox::MakeDynamicBox()
{
	CGameObject::MakeDynamicBox(m_width, m_height);
}

void CBox::MakeStaticBox()
{
	CGameObject::MakeStaticBox(m_width, m_height);
}
