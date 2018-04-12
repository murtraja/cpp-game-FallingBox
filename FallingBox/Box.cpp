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
	MakeDynamicBox(m_width, m_height);
	CGameObject::Init();
	return true;
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
	return loaded;
}

void CBox::SetDimension(int width, int height)
{
	m_width = width;
	m_height = height;
}
