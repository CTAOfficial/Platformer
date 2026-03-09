#pragma once
#include "Keybind.h"
#include <vector>

class InputAction {
private:
	std::vector<Keybind> binds;

public:

	InputAction(Keybind keybind) {
		AddBind(keybind);
	}
	InputAction(std::vector<Keybind> keybinds) {
		for (int i = 0; i < keybinds.size(); i++) {
			AddBind(keybinds[i]);
		}
	}

	void AddBind(Keybind bind) {
		binds.push_back(bind);
	}
	bool CheckConditions();
	virtual void Invoke() {}
};