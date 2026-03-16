#pragma once
#include "Sprites/Texture.h"
#include <map>
#include <string>

struct WorldDictionary {
private:
	std::map<std::string, Texture*> Definitions;

public:
	WorldDictionary(){}

	bool Define(std::string definition, Texture* texture) {
		if (Definitions.contains(definition)) {
			return false;
		}
		std::pair<std::string, Texture*> pair = std::pair<std::string, Texture*>{ definition, texture };
		Definitions.insert(pair);
		return true;
	}
	bool Undefine(std::string definition) {
		if (!Definitions.contains(definition)) { return false; }

		Definitions[definition] = nullptr;
		return true;
	}

	Texture* Fetch(std::string definition) {
		if (!Definitions.contains(definition)) { return nullptr; }
		return Definitions[definition];
	}
};