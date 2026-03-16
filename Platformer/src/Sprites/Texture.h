#pragma once
#include "Entities/Object.h"
#include <SDL3/SDL_render.h>
#include <string>

class Texture : public Object {
private:
	SDL_ScaleMode scaleMode;

protected:
	SDL_Texture* texture;

public:
	Texture(SDL_Texture* sdl_texture, SDL_ScaleMode mode = SDL_SCALEMODE_NEAREST);
	~Texture();

	int width;
	int height;

	SDL_Texture* SDLTexture() {
		return texture;
	}

	SDL_ScaleMode ScaleMode() const {
		return scaleMode;
	}
	void SetScaleMode(SDL_ScaleMode mode);

	static Texture* FromSurface(SDL_Renderer* renderer, SDL_Surface* surface);
	static Texture* LoadTexture(SDL_Renderer* renderer, std::string path);
	static bool LoadTexture(SDL_Renderer* renderer, std::string path, Texture& outTexture);
};