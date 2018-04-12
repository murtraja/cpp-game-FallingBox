#pragma once

#define GAME_WINDOW_WIDTH (float)CEngine::GetInstance().GetWindow().GetWidth()
#define GAME_WINDOW_HEIGHT (float)CEngine::GetInstance().GetWindow().GetHeight()

class CGameWindow
{
	int m_width, m_height;
	SDL_Window* m_sdlWindow;
public:
	CGameWindow();
	~CGameWindow();
	void SetDimension(int width, int height);
	bool Init();
	SDL_Window* GetSDLWindow();
	bool Destroy();
	int GetWidth() const;
	int GetHeight() const;
};

