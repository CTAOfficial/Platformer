#pragma once
#include <SDL3/SDL_keycode.h>

struct Keybind {
public:
	Keybind(SDL_Keycode key) {
		this->key = key;
	}

	SDL_Keycode key;
};