#pragma once
#include "Sprite.h"
#include <unordered_map>

class SpriteSheet {
public:
	SDL_Texture* texture;
	std::unordered_map<int, Sprite*> Sprites;

	Sprite* SpriteAtIndex(int index) {
		Sprite* sprite = Sprites.at(index);
		if (sprite) { return sprite; }
		return nullptr;
	}
};