#pragma once

#include "Engine_pch.h"
#include "Texture.h"

class CGameObject
{
protected:
	int m_x, m_y;
	CTexture m_texture;
	std::string m_id;
public:
	CGameObject();
	~CGameObject();
	virtual bool Init();
	virtual bool Update(double dt);
	virtual bool Render();
	virtual bool Destroy();
	bool HasValidId();
	std::string GetId();
	void SetId(std::string);
	void SetPosition(int x, int y);
};

