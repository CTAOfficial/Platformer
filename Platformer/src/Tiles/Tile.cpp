#include "Tile.h"
#include "Sprites/Sprite.h"
#include "Sprites/Texture.h"
#include "Renderers/SpriteRenderer.h"

Tile::Tile(Sprite* sprite)
{
	this->sprite = sprite;
	name = sprite->GetTexure().name;
}

Tile::Tile(Sprite* sprite, Vector2 pos) : Tile(sprite)
{
	position = pos;
}

Tile::Tile(Texture* texture)
{
	sprite = new Sprite{ texture };
	renderer = new SpriteRenderer{ *this, sprite };
}

Tile::Tile(Texture* texture, Vector2 pos) : Tile(texture)
{
	position = pos;
}

SDL_FRect* Tile::Rect()
{
	return sprite->rect;
}
