#include "World.h"

World::World(std::string name, Tilemap* tilemap) : World(name)
{
	this->tilemap = tilemap;

	for (auto& tile : tilemap->Tiles) {
		AddObject(tile);
	}
}
