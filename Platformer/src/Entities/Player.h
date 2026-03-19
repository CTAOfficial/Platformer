#pragma once
#include "VelocityObject.h"
#include <SDL3/SDL_render.h>
#include <Sprites/Sprite.h>
#include <vector>

enum Direction {
	Up,
	Down,
	Left,
	Right
};

class Game;
//class PlayerWidget;

class Player : public GameObject {

private:
	friend class PlayerWidget;


	PlayerWidget* widget;


	Vector2 firePos;
	float fireOffset = 2;
	SDL_Keycode LeftKey = NULL;
	SDL_Keycode RightKey = NULL;

	SDL_FRect collision;

	float speed = 100;
	float gravity = 100;


public:
	Player(SDL_Renderer* renderer, Vector2 pos);
	~Player();

	Sprite* sprite;
	

	void Update(Game& game, float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	void OnCollision(SDL_FRect rect);

	void SetLeftKey(SDL_Keycode key);
	void SetRightKey(SDL_Keycode key);
};