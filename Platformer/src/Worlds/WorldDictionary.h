#pragma once
#include "Sprites/Texture.h"
#include <map>


template <typename T>
struct WorldDictionary {
private:
	std::map<T, Texture*> Definitions;

public:
	WorldDictionary(){}

	bool Define(T definition, Texture* texture) {
		if (Definitions.contains(definition)) {
			return false;
		}
		std::pair<T, Texture*> pair = std::pair<T, Texture*>{ definition, texture };
		Definitions.insert(pair);
		return true;
	}
	bool Undefine(T definition) {
		if (!Definitions.contains(definition)) { return false; }

		Definitions[definition] = nullptr;
		return true;
	}

	Texture* Fetch(T definition) {
		if (!Definitions.contains(definition)) { return nullptr; }
		return Definitions[definition];
	}
};