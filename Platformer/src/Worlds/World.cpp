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

// hate this. Use as Band-aid if draw order become an issue and until draw orders are created
/*void World::Draw(SDL_Renderer* renderer)
{
    for (auto& tile : tilemap->Tiles()) {
        tile->Draw(renderer);
    }

    player->Draw(renderer);
}*/

void World::Update(Game& game, float deltaTime)
{
    // Collision
    if (player && tilemap) {
        for (auto& tile : tilemap->Tiles()) {
            if (SDL_HasRectIntersectionFloat(const_cast<SDL_FRect*>(tile->Rect()), const_cast<SDL_FRect*>(player->sprite->rect))) {

                // Check if player is above rect

            }
        }
    }

    Scene::Update(game, deltaTime);
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
