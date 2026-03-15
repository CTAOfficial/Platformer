#include "Tile.h"
#include "Sprites/Sprite.h"
#include "Sprites/Texture.h"
#include "Renderers/SpriteRenderer.h"

Tile::Tile(Texture* texture)
{
	sprite = new Sprite{ texture };
	renderer = new SpriteRenderer{ *this, sprite };
}
