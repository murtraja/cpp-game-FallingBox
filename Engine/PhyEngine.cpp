#include "Engine_pch.h"
#include "PhyEngine.h"
#include "Position.h"
#include "Engine.h"

const float CPhyEngine::m_worldWidth(50.f);

CPhyEngine::CPhyEngine()
	: m_phyWorld(b2Vec2(0.0f, -10.0f))
{
}


CPhyEngine::~CPhyEngine()
{
}

b2Vec2 CPhyEngine::ToPhyPosition(const CPosition& pixPosition)
{
	CPosition phyPosition(TranslateToCenter(pixPosition));
	phyPosition = ScaleToPhy(phyPosition);
	return phyPosition.ToBox2D();
}

CPosition CPhyEngine::ToPixPosition(const b2Vec2& phyPosition)
{
	CPosition pixPosition(phyPosition);
	pixPosition = ScaleToPix(pixPosition);

	pixPosition = TranslateToTopLeft(pixPosition);
	return pixPosition;
}

CPosition CPhyEngine::TranslateToCenter(const CPosition& pos)
{
	float newX = pos.m_x - GAME_WINDOW_WIDTH / 2.f;
	float newY = (GAME_WINDOW_HEIGHT / 2.f) - pos.m_y;
	return CPosition(newX, newY);
}

CPosition CPhyEngine::TranslateToTopLeft(const CPosition& pos)
{
	float newX = pos.m_x + GAME_WINDOW_WIDTH / 2.f;
	float newY = (GAME_WINDOW_HEIGHT / 2.f) - pos.m_y;
	return CPosition(newX, newY);
}

float CPhyEngine::ScaleToPhy(float value)
{
	float scalingFactor = m_worldWidth / GAME_WINDOW_WIDTH;
	float scaledValue = value * scalingFactor;
	return scaledValue;
}

CPosition CPhyEngine::ScaleToPhy(const CPosition& pos)
{
	return CPosition(ScaleToPhy(pos.m_x), ScaleToPhy(pos.m_y));
}

float CPhyEngine::ScaleToPix(float value)
{
	float scalingFactor = GAME_WINDOW_WIDTH / m_worldWidth;
	float scaledValue = value * scalingFactor;
	return scaledValue;
}

CPosition CPhyEngine::ScaleToPix(const CPosition& pos)
{
	return CPosition(ScaleToPix(pos.m_x), ScaleToPix(pos.m_y));
}

b2Body* CPhyEngine::CreateBody(b2BodyDef& bodyDef)
{
	return m_phyWorld.CreateBody(&bodyDef);
}
