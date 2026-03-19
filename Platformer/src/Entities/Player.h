#pragma once
#include "VelocityObject.h"
#include <SDL3/SDL_render.h>
#include "Sprites/Sprite.h"
#include "Renderers/SpriteRenderer.h"
#include <vector>

enum Direction {
	Up,
	Down,
	Left,
	Right
};

class Animation;
class Game;
//class PlayerWidget;

class Player : public GameObject {

private:
	friend class PlayerWidget;


	PlayerWidget* widget;

	float animationTimer = 0;
	float animationReset = 0.25f;

	Direction direction = Direction::Right;

	Vector2 firePos;
	float fireOffset = 2;
	SDL_Keycode LeftKey = NULL;
	SDL_Keycode RightKey = NULL;

	SDL_FRect collision;
	bool grounded = false;

	float speed = 100;
	float jumpForce = 50;
	float gravity = 100;


public:
	Player(SDL_Renderer* renderer, Vector2 pos);
	~Player();

	Animation* moveAnimation = nullptr;

	Sprite* idleSprite = nullptr;	
	Sprite* jumpSprite = nullptr;

	void Update(Game& game, float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	void OnCollision(GameObject& gameObject, SDL_FRect rect);

	Sprite* GetSprite() const {
		return GetRenderer<SpriteRenderer*>()->sprite;
	}
	void SetSprite(Sprite* sprite);

	template <typename T>
	T GetRenderer() const {
		return dynamic_cast<T>(renderer);
	}
	void SetLeftKey(SDL_Keycode key);
	void SetRightKey(SDL_Keycode key);
};