#pragma once

#include "Engine\GameObject.h"

class CBox : public CGameObject
{
public:
	CBox();
	~CBox();
	bool Init();
	virtual bool Update(float dt) override;
	virtual bool Render() override;
	virtual bool Destroy() override;
	bool SetTexture(std::string path);

	void MakeDynamicBox();
	void MakeStaticBox();
};

