#pragma once

#include "Engine_pch.h"
#include "Texture.h"
#include "Position.h"

class CGameObject
{
	b2Body *m_phyBody;
protected:
	CPosition m_position;
	int m_width, m_height;
	CTexture m_texture;
	std::string m_id;
public:
	CGameObject();
	~CGameObject();
	virtual bool Init();
	virtual bool Update(float dt);
	virtual bool Render();
	virtual bool Render(int width, int height);
	virtual bool Destroy();
	bool HasValidId();
	std::string GetId();
	void SetId(std::string);
	void SetPosition(int x, int y);
	void SetDimension(int width, int height);

	void MakeDynamicBox(int width, int height);
	void MakeStaticBox(int width, int height);
};

