#pragma once

#include "Engine_pch.h"

#define ASSETS_PATH "../assets/"

class CTexture
{
	SDL_Texture* m_sdlTexture;
	int m_width, m_height;

public:
	CTexture();
	~CTexture();

	bool loadFromFile(std::string path);
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
	void free();

	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);

	void Render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, 
		SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	
	int getWidth();
	int getHeight();
};

