#include "Player.h"
#include "../Game.h"
#include "../Input/Input.h"
#include "Renderers/SpriteRenderer.h"
#include "Sprites/Sprite.h"
#include "Utilities/Assets.h"
#include "Widgets/PlayerWidget.h"
#include <numbers>
#include <iostream>


Player::Player(SDL_Renderer* renderer, Vector2 pos) : GameObject(pos)
{
	sprite = new Sprite{ Assets::Get<Texture*>("images/player.png")};
	sprite->scale = { 0.15f, 0.15f };

	this->renderer = new SpriteRenderer(*this, sprite);

	name = "big cheese";
	tag = "Player";

	widget = new PlayerWidget{ this };
	widget->Visible = false;
}

Player::~Player()
{
	delete widget;
}

void Player::Update(Game& game, float deltaTime)
{
	float grav = gravity * deltaTime;
	float finalSpeed = speed * deltaTime;

	if (Input::GetKey(SDLK_TAB)) {
		widget->Toggle();
	}


	if (Input::GetKeyDown(LeftKey)) {
		position.X -= finalSpeed;
	}
	if (Input::GetKeyDown(RightKey)) {
		position.X += finalSpeed;
	}

	if (Input::GetKey(SDLK_SPACE)) {
		// Jump
		position.Y -= 5;
	}

	position.Y += grav;

}

void Player::Draw(SDL_Renderer* renderer)
{
	GameObject::Draw(renderer);

	if (!DebugMode) { return; }

	if (collision.w > 0 && collision.h > 0) {
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &collision);

		// I suspect my Sprite is very far from my player position, TODO: Fix later
		//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		//(renderer, position.X * 0.5f, position.Y * 0.5f, collision.x + (collision.w * 0.5f), collision.y + (collision.h * 0.5f));
	}
}

void Player::OnCollision(SDL_FRect rect)
{
	collision = rect;

	// Check if player is above rect
	float pos = rect.h - rect.y;
	if (position.Y > pos) {
		position.Y = -pos;
	}
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