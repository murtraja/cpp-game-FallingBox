#pragma once

#include "Box.h"
#include "Engine/InputManager.h"

class CGame : public IInputListener
{
	std::vector<CBox*> m_boxes;
	CBox m_ground;
public:
	CGame();
	~CGame();
	bool Init();
	void Start();
	bool Destroy();
	void SpawnBox(int x, int y);

	virtual void OnInputEvent(std::vector<InputInfo> infos) override;

};

