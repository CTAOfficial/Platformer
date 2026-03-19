#pragma once
#include "Scenes/Scene.h"
#include "WorldDictionary.h"
#include "Tiles/Tilemap.h"

class Player;

class World : public Scene {
private:
	Tilemap* tilemap = nullptr;
	
public:
	//const std::string FileExtension = ".world";
	Player* player = nullptr;

	World(std::string name) : Scene(name){}
    World(std::string name, Tilemap* tilemap);

	//`void Draw(SDL_Renderer* renderer) override;
	void Update(Game& game, float deltaTime) override;

	static World* FromFile(std::string path, WorldDictionary& dictionary);
};