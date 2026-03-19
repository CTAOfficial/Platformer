#pragma once
#include "Entities/GameObject.h"
#include <SDL3/SDL_render.h>

class Renderer {
protected:
	GameObject* gameObject;

public:
	Renderer(GameObject& gameObject) : gameObject{ &gameObject }{}

	virtual void Render(SDL_Renderer* renderer){}
};