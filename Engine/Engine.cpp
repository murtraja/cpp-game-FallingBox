#include "Engine_pch.h"
#include "Engine.h"
#include "GameWindow.h"
#include "Renderer.h"
#include "GameFont.h"

CEngine::CEngine()
	: m_engineRunning(false)
	, m_deltaTime(0.f)
{
}


CEngine& CEngine::GetInstance()
{
	static CEngine engine;
	return engine;
}

CEngine::~CEngine()
{
}

bool CEngine::Init()
{
	printf("Engine Init\n");

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	
	if (!m_gameWindow.Init())
	{
		return false;
	}

	if(!m_renderer.Init())
	{
		return false;
	}

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	
	return true;
}

void CEngine::Run()
{
	// the main game loop is here
	m_engineRunning = true;
	unsigned long lastFrameStartTime = SDL_GetTicks();
	while (m_engineRunning)
	{
		unsigned long currentFrameStartTime = SDL_GetTicks();
		unsigned long elapsedTime = currentFrameStartTime - lastFrameStartTime;
		ProcessInputs();
		UpdateGameState((double)elapsedTime);
		RenderWorld();
		lastFrameStartTime = currentFrameStartTime;
		if (m_deltaTime < ENGINE_FRAME_TIME)
		{
			SDL_Delay(ENGINE_FRAME_TIME - m_deltaTime);
		}
	}
}

bool CEngine::Destroy()
{
	printf("Engine destroy\n");

	if (!m_renderer.Destroy())
	{
		return false;
	}

	if (!m_gameWindow.Destroy())
	{
		return false;
	}

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	return true;
}

void CEngine::ProcessInputs()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		//User requests quit
		if (e.type == SDL_QUIT)
		{
			m_engineRunning = false;
		}
	}
}

void CEngine::UpdateGameState(double dt)
{
	m_world.Update(dt);

	b2Vec2 gravity(0.0f, -10.0f);

	// Construct a world object, which will hold and simulate the rigid bodies.
	b2World world(gravity);

	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	b2Body* groundBody = world.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(50.0f, 10.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	b2Body* body = world.CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.3f;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);

	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;
}

void CEngine::RenderWorld()
{
	m_renderer.Clear();
	m_world.Render();
	m_renderer.Draw();
}

CGameWindow& CEngine::GetWindow()
{
	return m_gameWindow;
}

CRenderer& CEngine::GetRenderer()
{
	return m_renderer;
}

CGameFont& CEngine::GetFont()
{
	return m_font;
}

CWorld& CEngine::GetWorld()
{
	return m_world;
}
