#pragma once
#include "../Scenes/Scene.h"

class World : public Scene {
public:
	World(std::string name) : Scene(name){}

	static World* FromFile(std::string path);
};