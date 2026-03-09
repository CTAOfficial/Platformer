#pragma once
#include "PlayerAction.h"

class MovementAction : public PlayerAction {
public:
	MovementAction(Player* player, Keybind keybind   ) : PlayerAction(player, keybind){}

	void Invoke() override;
};