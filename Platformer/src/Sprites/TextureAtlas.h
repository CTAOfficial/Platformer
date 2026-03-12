#pragma once
#include "Texture.h"

class TextureAtlas {
private:
	Texture* texture;

public:
	Texture* FromRect(SDL_Renderer* renderer, SDL_FRect* rect) {
		FromRect(renderer ,new SDL_Rect{(int)rect->x,(int)rect->y, (int)rect->w, (int)rect->h});
	}
	Texture* FromRect(SDL_Renderer* renderer, SDL_Rect* rect);
};