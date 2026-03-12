#include "SpriteSheet.h"
#include <cassert>

SpriteSheet::SpriteSheet(Texture* input)
{
	assert(!input, "SpriteSheet input cannot be nullptr!");

	texture = input;

	//..TODO: Create sprites from texture
}

Sprite* SpriteSheet::FromRect(SDL_Rect rect)
{
	//Texture* texture
	//Sprite* sprite = 

	return nullptr;
}

SpriteSheet* SpriteSheet::FromTextureAtlas(TextureAtlas atlas)
{
	return nullptr;
}
