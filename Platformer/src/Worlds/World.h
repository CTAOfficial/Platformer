#pragma once
#include "Scenes/Scene.h"
#include "Tiles/Tilemap.h"
#include "WorldDictionary.h"

class World : public Scene {
private:
	Tilemap* tilemap = nullptr;
	
public:
	World(std::string name) : Scene(name){}
	World(std::string name, Tilemap* tilemap) : World(name) { this->tilemap = tilemap; }
	const std::string FileExtension = ".world";

	template<typename T>
	static World* FromFile(std::string path, WorldDictionary<T>& dictionary);
};