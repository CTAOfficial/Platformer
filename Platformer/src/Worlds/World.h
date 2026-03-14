#pragma once
#include "../Scenes/Scene.h"
#include "Tiles/Tilemap.h"

class World : public Scene {
private:
	Tilemap tilemap;
	
public:
	World(std::string name) : Scene(name){}

	static World* FromFile(std::string path, WorldDictionary dictionary);
};