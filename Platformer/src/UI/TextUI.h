#pragma once

#include "../Entities/Basic2D.h"
#include <string>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_pixels.h>
#include <SDL3/SDL_render.h>

class Font;

class TextUI : public Basic2D {
protected:
	SDL_Surface* surface = nullptr;

	~TextUI();

public:
	TextUI(std::string fontPath, SDL_Renderer* renderer, Vector2 pos, RGBA rgba);
	TextUI(Font* font, Vector2 pos, RGBA rgba = RGBA::White);

	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Color color = { 255, 255, 255, SDL_ALPHA_OPAQUE };
	Font* font = nullptr;
	std::string text;
	Vector2 offset;


	void Draw(SDL_Renderer* renderer) override;
	void SetText(std::string text);
	void SetSize(float size);
};