#pragma once

#include "Engine_pch.h"
#include "Position.h"

#define ASSETS_PATH "../assets/"

class CTexture
{
	SDL_Texture* m_sdlTexture;
	int m_width, m_height;

public:
	CTexture();
	~CTexture();

	bool LoadFromFile(std::string path);
	bool LoadFromRenderedText(std::string textureText, SDL_Color textColor);
	void Free();

	void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	void SetBlendMode(SDL_BlendMode blending);
	void SetAlpha(Uint8 alpha);

	void Render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, 
		SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void Render(const CPosition&);
	
	int GetWidth();
	int GetHeight();

	void SetDimension(int width, int height);
};

