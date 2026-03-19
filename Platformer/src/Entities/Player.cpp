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