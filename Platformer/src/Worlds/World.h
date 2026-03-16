#pragma once
#include "Scenes/Scene.h"
#include "WorldDictionary.h"
#include "Sprites/Texture.h"
#include "Tiles/Tilemap.h"
#include "Tiles/Tile.h"
#include "Vector2.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>



class World : public Scene {
private:
	Tilemap* tilemap = nullptr;
	
public:
	//const std::string FileExtension = ".world";

	World(std::string name) : Scene(name){}
    World(std::string name, Tilemap* tilemap);

	static World* FromFile(std::string path, WorldDictionary& dictionary);
};