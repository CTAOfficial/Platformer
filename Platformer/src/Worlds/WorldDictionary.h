#pragma once
#include "Sprites/Texture.h"
#include <map>

template <typename T>
struct WorldDictionary {
private:
	std::map<T, Texture*> Definitions;

public:
	WorldDictionary(){}

	bool Define(T definition, Texture* texture);
	bool Undefine(T definition);

	Texture* Fetch(T definition);
};