#include "World.h"
#include "Entities/Player.h"
#include <iostream>
#include <fstream>
#include <SDL3/SDL_rect.h>

World::World(std::string name, Tilemap* tilemap) : World(name)
{
	this->tilemap = tilemap;

	for (auto& tile : tilemap->Tiles()) {
		AddObject(tile);
	}
}

void World::Update(Game& game, float deltaTime)
{
    Scene::Update(game, deltaTime);

    // Collision
    if (player && !colliders.empty()) {
        for (auto& tile : colliders) {

            SDL_FRect* tRect = tile->Rect();
            SDL_FRect* pRect = player->sprite->rect;
            if (SDL_HasRectIntersectionFloat(const_cast<SDL_FRect*>(tRect), const_cast<SDL_FRect*>(pRect))) {
                player->OnCollision(*tRect);
                break; // we don't care about other tile collision
            }
        }
    }
}

void World::SetCollider(std::string texture)
{
    for (auto& tile : tilemap->Tiles()) {

        if (tile->sprite->GetTexure().name == texture) {
            colliders.push_back(tile);
        }
    }
}

void World::UnsetCollider(std::string texture)
{
    for (auto& tile : colliders) {

        if (tile->sprite->GetTexure().name == texture) {
            std::erase(colliders, tile);
        }
    }
}

World* World::FromFile(std::string path, WorldDictionary& dictionary)
{
    std::string full = path;
    full += ".world";

    std::ifstream file(full);
    if (!file.is_open()) {
        std::cerr << "Error opening the file!\n";
        return nullptr;
    }

    Tilemap* tilemap = new Tilemap();
    int x = 0;
    int y = 0;

    char ch;
    while (!file.eof()) {
        file.get(ch);

        std::string string;
        string += ch;

        Texture* def = dictionary.Fetch(string);
        if (def) {
            Tile* tile = new Tile{ def, Vector2{ -x * def->width, y * def->height } };
            tilemap->Add(tile);
        }
        else if (string == "\n") {
            //x = -1;
            x = 0;
            y++;
        }
        else {
            x--;
        }
        //x++;
    }

    file.close();

    World* world;
    std::string::size_type extension(path.find_last_of('.'));
    std::string name = path.substr(path.find_last_of("/", extension));

    if (tilemap->Size() > 0) {
        world = new World{ name, tilemap };
    }
    else {
        //..TODO: Log
        world = new World{ name };
        delete tilemap;
        std::cout << "No tiles created for world '*" << name << "'.\n";
    }

    return world;
}
