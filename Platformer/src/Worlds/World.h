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

	template<typename T>
	static World* FromFile(std::string path, WorldDictionary<T>& dictionary) {
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
                Tile* tile = new Tile{ def, Vector2{ x, y } };
                tilemap->Add(tile);
            }
            else if (string == "\n") {
                x = -1;
                y++;
            }
            else {
                x--;
                x++;
            }
        }

        file.close();

        /*std::string line;
        std::queue<std::string> lines;

        while (std::getline(file, line)) {

            lines.push(line + "\n");
        }
        file.close();

        int x = 0;
        int y = 0;
        Tilemap* tilemap = new Tilemap();

        while (!lines.empty()) {
            line = lines.front();
            std::stringstream stream(line);
            std::string string;
            std::queue<std::string> strings;

            while (std::getline(stream, string)) {
                strings.push(string);
            }

            while (!strings.empty()) {
                std::string str = strings.front();

                Texture* def = dictionary.Fetch(str);
                if (def) {
                    Tile* tile = new Tile{ def, Vector2{ x, y } };
                    tilemap->Add(tile);
                }
                else if (line == "\n") {
                    x = -1;
                    y++;
                }
                else {
                    x--;
                    x++;
                }

                strings.pop();
            }

            lines.pop();
        }*/

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
};