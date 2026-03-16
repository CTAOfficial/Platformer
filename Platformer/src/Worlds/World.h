#pragma once
#include "Scenes/Scene.h"
#include "WorldDictionary.h"
#include "Tiles/Tilemap.h"

class World : public Scene {
private:
	Tilemap* tilemap = nullptr;
	
public:
	//const std::string FileExtension = ".world";

	World(std::string name) : Scene(name){}
    World(std::string name, Tilemap* tilemap);

	static World* FromFile(std::string path, WorldDictionary& dictionary);
};