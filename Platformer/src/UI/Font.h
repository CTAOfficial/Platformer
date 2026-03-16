#pragma once
#include "Entities/Object.h"
#include <SDL3_ttf/SDL_ttf.h>
#include "RGBA.h"

class Font : public Object {
private:
	TTF_Font* font;

public:
	using Object::Object;
	Font(TTF_Font* font);
	Font(TTF_Font* font, RGBA rgba);
	Font(TTF_Font* font, SDL_Color color);
	~Font();

	SDL_Color color = { 255, 255, 255, SDL_ALPHA_OPAQUE };

	void SetSize(float size);

	TTF_Font* SDLFont() const {
		return font;
	}
};