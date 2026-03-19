#pragma once
#include "Renderer.h"

class Sprite;

class SpriteRenderer : public Renderer {

public:
	SpriteRenderer(GameObject& gameObject, Sprite* sprite = nullptr);
	Sprite* sprite;

	void Render(SDL_Renderer* renderer) override;
};