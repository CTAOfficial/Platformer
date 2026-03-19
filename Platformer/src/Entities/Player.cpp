#include "Player.h"
#include "../Game.h"
#include "../Input/Input.h"
#include "Renderers/SpriteRenderer.h"
#include "Sprites/Sprite.h"
#include "Utilities/Assets.h"
#include "Widgets/PlayerWidget.h"
#include "Animations/Animation.h"
#include <numbers>
#include <iostream>


Player::Player(SDL_Renderer* renderer, Vector2 pos) : GameObject(pos)
{
	this->renderer = new SpriteRenderer(*this);

	name = "big cheese";
	tag = "Player";

	widget = new PlayerWidget{ this };
	widget->Visible = false;
}

Player::~Player()
{
	delete widget;
	delete renderer;
}

void Player::Update(Game& game, float deltaTime)
{
	if (Input::GetKey(SDLK_TAB)) {
		widget->Toggle();
	}

	bool isMoving = false;
	float finalSpeed = speed * deltaTime;

	if (Input::GetKeyDown(LeftKey)) {
		position.X -= finalSpeed;
		isMoving = true;
		direction = Direction::Left;
	}
	if (Input::GetKeyDown(RightKey)) {
		position.X += finalSpeed;
		isMoving = true;
		direction = Direction::Right;
	}

	if (isMoving) {
		switch (direction) {
		case Direction::Left:
			GetSprite()->flipMode = SDL_FlipMode::SDL_FLIP_HORIZONTAL;
			break;
		case Direction::Right:
			GetSprite()->flipMode = SDL_FlipMode::SDL_FLIP_NONE;
			break;
		}

		if (moveAnimation) {
			animationTimer -= (1 * deltaTime);

			if (animationTimer <= 0) {
				animationTimer = animationReset;
				moveAnimation->Animate();
				SetSprite(moveAnimation->frame);
			}
		}
	}	
	else {
		SetSprite(idleSprite);
		animationTimer = animationReset;
	}

	// Ground Check, Jumping & Gravity
	float grav = gravity * deltaTime;
	if (Input::GetKey(SDLK_SPACE) && grounded) {
		position.Y -= jumpForce;
		grounded = false;
		SetSprite(jumpSprite);
	}

	position.Y += grav;

}

void Player::Draw(SDL_Renderer* renderer)
{
	GameObject::Draw(renderer);

	if (!DebugMode) { return; }
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderRect(renderer, GetSprite()->rect);

	if (collision.w > 0 && collision.h > 0) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderRect(renderer, &collision);

		// I suspect my Sprite is very far from my player position, TODO: Fix later
		//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		//(renderer, position.X * 0.5f, position.Y * 0.5f, collision.x + (collision.w * 0.5f), collision.y + (collision.h * 0.5f));
	}
}

void Player::OnCollision(GameObject& gameObject, SDL_FRect rect)
{
	collision = rect;
	grounded = true;

	// Check if player is above rect
	float pos = rect.h - rect.y;
	if (position.Y > pos) {
		position.Y = -pos;
	}
}

void Player::SetSprite(Sprite* sprite)
{
	GetRenderer<SpriteRenderer*>()->sprite = sprite;
}


#pragma region Key Setting
void Player::SetRightKey(SDL_Keycode key)
{
	RightKey = key;
}
void Player::SetLeftKey(SDL_Keycode key)
{
	LeftKey = key;
}
#pragma endregion













































































//uranus