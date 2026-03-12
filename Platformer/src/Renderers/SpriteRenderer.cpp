#include "SpriteRenderer.h"
#include "Sprites/Sprite.h"

SpriteRenderer::SpriteRenderer(GameObject& gameObject, Sprite* sprite) : Renderer(gameObject)
{
	this->sprite = sprite;
}

void SpriteRenderer::Render(SDL_Renderer* renderer)
{
	if (sprite != nullptr) {
		sprite->position = gameObject.position;
		sprite->Draw(renderer);
	}
}
