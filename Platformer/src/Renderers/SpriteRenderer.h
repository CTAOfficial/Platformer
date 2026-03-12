#pragma once
#include "Renderer.h"

class Sprite;

class SpriteRenderer : public Renderer {
private:
	Sprite* sprite;

public:
	SpriteRenderer(GameObject& gameObject, Sprite* sprite = nullptr);

	void Render(SDL_Renderer* renderer) override;
};