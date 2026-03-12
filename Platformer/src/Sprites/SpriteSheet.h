#pragma once
#include "Sprite.h"
#include "TextureAtlas.h"
#include <SDL3/SDL_render.h>
#include <unordered_map>

class SpriteSheet {
private:
	std::unordered_map<int, Sprite*> sprites;


public:
	SpriteSheet(Texture* input);

	Texture* texture;

	std::vector<Sprite*> Sprites() const {
		std::vector<Sprite*> vec;
		for (const auto& pair : sprites) {
			vec.push_back(pair.second);
		}

		return vec;
	}
	Sprite* AtIndex(int index) {
		Sprite* sprite = sprites.at(index);
		if (sprite) { return sprite; }
		return nullptr;
	}
	Sprite* FromRect(SDL_FRect* rect) {
		//FromRect(static_cast<SDL_Rect*>(&rect));
	}
	Sprite* FromRect(SDL_Rect rect);

	static SpriteSheet* FromTextureAtlas(TextureAtlas atlas);
};