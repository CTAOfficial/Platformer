#pragma once
#include "Texture.h"
#include "Entities/Object.h"
#include "Vector2.h"
#include <string>

class Sprite : public Object {
private:
	Texture* texture = nullptr;

protected:
	Sprite();

public:
	static Sprite* MissingSprite;

	using Object::Object;
	Sprite(Texture* texture);
	Sprite(SDL_Texture* sdl_texture);
	Sprite(SDL_Renderer* renderer, std::string path);
	~Sprite();

	// Draw From Top Left
	//bool DrawFromTL = false;

	Vector2 position;
	Vector2 centerPos;
	Vector2 scale = Vector2::One;
	float rotation = 0;
	SDL_FlipMode flipMode = SDL_FLIP_NONE;

	Vector2 center;
	SDL_FRect* rect;

	void Draw(SDL_Renderer* renderer);

	Texture& GetTexure() {
		return *texture;
	}
	bool SetTexture(Texture* texture);
};