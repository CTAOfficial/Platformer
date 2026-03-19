#pragma once
#include "Scenes/Scene.h"
#include "WorldDictionary.h"
#include "Tiles/Tilemap.h"

class Player;

class World : public Scene {
private:
	Tilemap* tilemap = nullptr;
	std::vector<Tile*> colliders;
	
public:
	//const std::string FileExtension = ".world";
	Player* player = nullptr;

	World(std::string name) : Scene(name){}
    World(std::string name, Tilemap* tilemap);

	void Update(Game& game, float deltaTime) override;
	void SetCollider(std::string texture);
	void UnsetCollider(std::string texture);

	static World* FromFile(std::string path, WorldDictionary& dictionary);
};