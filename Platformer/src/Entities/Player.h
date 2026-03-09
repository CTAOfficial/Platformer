#pragma once
#include "VelocityObject.h"
#include <SDL3/SDL_render.h>
#include <vector>

enum Direction {
	Up,
	Down,
	Left,
	Right
};

class Game;
class PlayerWidget;

class Player : public GameObject {

private:
	PlayerWidget* widget;

	Vector2 firePos;
	float fireOffset = 2;
	SDL_Keycode UpKey = NULL;
	SDL_Keycode DownKey = NULL;
	SDL_Keycode LeftKey = NULL;
	SDL_Keycode RightKey = NULL;


public:
	Player(int index, SDL_Renderer* renderer, Vector2 pos);
	~Player();

	int playerIndex = 0;
	float speed = 10;

	void Update(Game& game, float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;


	void SetUpKey(SDL_Keycode key);
	void SetDownKey(SDL_Keycode key);
	void SetLeftKey(SDL_Keycode key);
	void SetRightKey(SDL_Keycode key);
};