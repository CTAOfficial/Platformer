#pragma once
#include "Input.h"
#include <SDL3/SDL_keycode.h>

struct Keybind {
public:
	Keybind(SDL_Keycode key) {
		this->key = key;
	}
	
	SDL_Keycode key;

	bool Press = false;
	bool Hold = false;
	bool Release = false;

	bool CheckConditions() const {
		if (Press && Input::GetKey(key)) {
			return true;
		}
		if (Hold && Input::GetKeyDown(key)) {
			return true;
		}
		if (Release && Input::GetKeyUp(key)) {
			return true;
		}

		return false;
	}
};