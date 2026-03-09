#pragma once
#include "../Input/InputAction.h"

class Player;
class PlayerAction : public InputAction {
protected:
	Player* player;

public:
	PlayerAction(Player* player, Keybind keybind) : InputAction(keybind) {
		this->player = player;
	}
};