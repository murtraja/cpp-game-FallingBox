#include "Engine_pch.h"
#include "Texture.h"
#include "Engine.h"
#include "Position.h"

CTexture::CTexture()
{
}


CTexture::~CTexture()
{
}

bool CTexture::LoadFromFile(std::string path)
{
	Free();
	SDL_Texture* newTexture = NULL;

	path = ASSETS_PATH + path;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (!loadedSurface)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		return false;
	}
	
	//Color key image
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

	//Create texture from surface pixels
	newTexture = SDL_CreateTextureFromSurface(CEngine::GetInstance().GetRenderer().GetSDLRenderer(), loadedSurface);
	if (!newTexture)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		return false;
	}

	m_width = loadedSurface->w;
	m_height = loadedSurface->h;

	SDL_FreeSurface(loadedSurface);

	m_sdlTexture = newTexture;
	return m_sdlTexture != NULL;
}

bool CTexture::LoadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	Free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(CEngine::GetInstance().GetFont().GetSDLFont(), textureText.c_str(), textColor);
	if (!textSurface)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	
	//Create texture from surface pixels
	m_sdlTexture = SDL_CreateTextureFromSurface(CEngine::GetInstance().GetRenderer().GetSDLRenderer(), textSurface);
	if (!m_sdlTexture)
	{
		printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		return false;
	}
		
	//Get image dimensions
	m_width = textSurface->w;
	m_height = textSurface->h;
		
	SDL_FreeSurface(textSurface);

	return m_sdlTexture != NULL;
}

void CTexture::Free()
{
	if (m_sdlTexture)
	{
		SDL_DestroyTexture(m_sdlTexture);
		m_sdlTexture = NULL;
		m_width = 0;
		m_height = 0;
	}
}

void CTexture::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(m_sdlTexture, red, green, blue);
}

void CTexture::SetBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(m_sdlTexture, blending);
}

void CTexture::SetAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(m_sdlTexture, alpha);
}

void CTexture::Render(int x, int y, SDL_Rect* clip /*= NULL*/, double angle /*= 0.0*/, SDL_Point* center /*= NULL*/, SDL_RendererFlip flip /*= SDL_FLIP_NONE*/)
{
	SDL_Rect renderQuad = { x, y, m_width, m_height };

	if (clip)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx(CEngine::GetInstance().GetRenderer().GetSDLRenderer(), 
		m_sdlTexture, clip, &renderQuad, angle, center, flip);
}

void CTexture::Render(const CPosition& position)
{
	Render(position.m_x, position.m_y);
}

int CTexture::GetWidth()
{
	return m_width;
}

int CTexture::GetHeight()
{
	return m_height;
}

void CTexture::SetDimension(int width, int height)
{
	m_width = width;
	m_height = height;
}
