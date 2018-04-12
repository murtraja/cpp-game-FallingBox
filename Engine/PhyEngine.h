#pragma once

#include "Engine_pch.h"
#include "Position.h"

class CPhyEngine
{
	b2World m_phyWorld;
	static const float m_worldWidth;
public:
	CPhyEngine();
	~CPhyEngine();



	static b2Vec2 ToPhyPosition(const CPosition& pixPosition);
	static CPosition ToPixPosition(const b2Vec2& phyPosition);
	
	static CPosition TranslateToCenter(const CPosition& pos);
	static CPosition TranslateToTopLeft(const CPosition& pos);
	
	static float ScaleToPhy(float value);
	static CPosition ScaleToPhy(const CPosition& pos);
	
	static float ScaleToPix(float value);
	static CPosition ScaleToPix(const CPosition& pos);
	
	b2Body* CreateBody(b2BodyDef& bodyDef);
};

