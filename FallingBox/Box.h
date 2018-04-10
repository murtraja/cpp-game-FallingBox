#pragma once

#include "Engine\GameObject.h"

class CBox : public CGameObject
{
	int m_width, m_height;
public:
	CBox();
	~CBox();
	virtual bool Init() override;
	virtual bool Update(double dt) override;
	virtual bool Render() override;
	virtual bool Destroy() override;
	bool SetTexture(std::string path);
	void SetDimension(int width, int height);
};

