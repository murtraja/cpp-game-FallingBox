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
	return true;
}

bool CBox::Update(double dt)
{
	return true;
}

bool CBox::Render()
{
	CGameObject::Render(m_width, m_height);
	return true;
}

bool CBox::Destroy()
{
	return true;
}

bool CBox::SetTexture(std::string path)
{
	bool loaded = m_texture.loadFromFile(path);
	return loaded;
}

void CBox::SetDimension(int width, int height)
{
	m_width = width;
	m_height = height;
}
