#include "InputAction.h"

bool InputAction::CheckConditions()
{
	for (auto& bind : binds) {
		if (bind.CheckConditions()) { continue; }
		return false;
	}

	return true;
}
