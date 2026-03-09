#include "Player.h"
#include "../Game.h"
#include "../Input/Input.h"
#include "Sprites/Sprite.h"
#include "Widgets/PlayerWidget.h"
#include <numbers>
#include <iostream>


Player::Player(int index, SDL_Renderer* renderer, Vector2 pos) : GameObject(pos)
{
	sprite = new Sprite{ renderer, "build/images/player.png" };
	sprite->scale = { 0.15f, 0.15f };

	playerIndex = index;
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
	if (Input::GetKey(SDLK_TAB)) {
		widget->Toggle();
	}

	bool accelerating = false;

	if (Input::GetKeyDown(LeftKey)) {

	}
	if (Input::GetKeyDown(RightKey)) {

	}

	if (Input::GetKey(SDLK_SPACE)) {
		// Jump
	}

}

void Player::Draw(SDL_Renderer* renderer)
{
	GameObject::Draw(renderer);

}


#pragma region Key Setting
void Player::SetUpKey(SDL_Keycode key)
{
	UpKey = key;
}
void Player::SetDownKey(SDL_Keycode key)
{
	DownKey = key;
}
void Player::SetRightKey(SDL_Keycode key)
{
	RightKey = key;
}
void Player::SetLeftKey(SDL_Keycode key)
{
	LeftKey = key;
}
#pragma endregion
