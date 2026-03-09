#include "Input.h"
#include <algorithm>
#include <iostream>


std::vector<SDL_Keycode> Input::downKeys;
std::vector<SDL_Keycode> Input::upKeys;
std::vector<SDL_Keycode> Input::pressedKeys;

void Input::Process(SDL_Event& event)
{
	switch (event.type)
	{

	case SDL_EVENT_KEY_DOWN:
		Input::HandleKeyDown(event.key.key);
		break;
	case SDL_EVENT_KEY_UP:
		Input::HandleKeyUp(event.key.key);
		break;
	}
}

void Input::HandleKeyDown(SDL_Keycode key)
{
	auto iterator = std::find(downKeys.begin(), downKeys.end(), key);
	if (iterator != downKeys.end()) {
		return;
	}

	pressedKeys.push_back(key);
	downKeys.push_back(key);
}

void Input::HandleKeyUp(SDL_Keycode key)
{
	upKeys.push_back(key);

	auto iterator = std::find(downKeys.begin(), downKeys.end(), key);
	if (iterator != downKeys.end()) {
		downKeys.erase(iterator);
	}
}

void Input::Update()
{
	pressedKeys.clear();
	upKeys.clear();
}

bool Input::GetKey(SDL_Keycode key)
{
	for (int i = 0; i < pressedKeys.size(); i++) {
		if (pressedKeys[i] == key) { return true; }
	}
	return false;
}

bool Input::GetKeyUp(SDL_Keycode key)
{
	for (int i = 0; i < upKeys.size(); i++) {
		if (upKeys[i] == key) { return true; }
	}
	return false;
}

bool Input::GetKeyDown(SDL_Keycode key)
{
	for (int i = 0; i < downKeys.size(); i++) {
		if (downKeys[i] == key) { return true; }
	}

	return false;
}
