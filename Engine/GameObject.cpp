#include "Engine_pch.h"
#include "GameObject.h"
#include "Engine.h"


void CGameObject::MakeDynamicBox(int width, int height)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	CPosition centerPosition(m_position.m_x + width / 2, m_position.m_y + height / 2);
	CPosition phyPosition = CPhyEngine::ToPhyPosition(centerPosition);
	bodyDef.position = phyPosition.ToBox2D();
	m_phyBody = CEngine::GetInstance().GetPhyEngine().CreateBody(bodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(CPhyEngine::ScaleToPhy(width) / 2, CPhyEngine::ScaleToPhy(height) / 2);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 1.f;
	m_phyBody->CreateFixture(&fixtureDef);
}

void CGameObject::MakeStaticBox(int width, int height)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	CPosition centerPosition(m_position.m_x + width / 2, m_position.m_y + height / 2);
	CPosition phyPosition = CPhyEngine::ToPhyPosition(centerPosition);
	bodyDef.position = phyPosition.ToBox2D();
	m_phyBody = CEngine::GetInstance().GetPhyEngine().CreateBody(bodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(CPhyEngine::ScaleToPhy(width) / 2, CPhyEngine::ScaleToPhy(height) / 2);
	m_phyBody->CreateFixture(&boxShape, 0.f);
}

CGameObject::CGameObject()
	: m_phyBody(nullptr)
	, m_position(0,0)
	, m_width(0)
	, m_height(0)
	, m_id("")
{
}


CGameObject::~CGameObject()
{
}

bool CGameObject::Init()
{
	return true;
}

bool CGameObject::Update(float dt)
{
	if (m_phyBody)
	{
		CPosition centerPosition = CPhyEngine::ToPixPosition(m_phyBody->GetPosition());
		m_position.m_x = centerPosition.m_x - m_width / 2;
		m_position.m_y = centerPosition.m_y - m_height / 2;
	}
	return true;
}

bool CGameObject::Render()
{
	m_texture.Render(m_position);
	return true;
}

bool CGameObject::Render(int width, int height)
{
	SDL_Rect objectViewPort = { m_position.m_x, m_position.m_y, width, height };
	//SDL_RenderSetViewport(CEngine::GetInstance().GetRenderer().GetSDLRenderer(), &objectViewPort);
	static float rotation = 45;
	/*if (m_id == "box")
	{
		static int inc = 0;
		inc++;
		if(inc%45 == 0)
			rotation = inc;
	}*/
	m_texture.Render(m_position.m_x, m_position.m_y, nullptr, m_phyBody->GetAngle()*RADTODEG*-1);
	return true;
}

bool CGameObject::Destroy()
{
	return true;
}

bool CGameObject::HasValidId()
{
	bool isValid = (m_id != "");
	return isValid;
}

std::string CGameObject::GetId()
{
	return m_id;
}

void CGameObject::SetId(std::string id)
{
	m_id = id;
}

void CGameObject::SetPosition(int x, int y)
{
	m_position.Set(x, y);
}

void CGameObject::SetDimension(int width, int height)
{
	m_width = width;
	m_height = height;
}
