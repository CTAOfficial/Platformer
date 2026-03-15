#include "World.h"
#include <fstream>
#include <iostream>
#include <string>

template<typename T>
World* World::FromFile(std::string path, WorldDictionary<T>& dictionary)
{
    // Open the input file named "input.txt"
    std::ifstream file(path + FileExtension);

    // Check if the file is successfully opened
    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << endl;
        return 1;
    }

    int x = 0;
    int y = 0;

    Tilemap* tilemap = new Tilemap();

    char ch;
    while (!file.eof()) {
        file.get(ch);

        Texture* def = dictionary.Fetch(ch);
        if (def) {
            Tile* tile = new Tile{ def, new Vector2 { x, y } };
            tilemap->Add(tile);
        }
        else{
            switch (ch) {
                default:
                    x--;
                    break;
                case "\n":
                    x = -1;
                    y++;
                    break;
            }
        }
        x++;
    }
    file.close();

    World* world;
    std::string::size_type extension(path.find_last_of('.'));
    std::string name = path.substr(path.find_last_of("/\\", extension));

    if (tilemap->Size() == 0) {
        delete tilemap;
        world = new World{ name, tilemap };
    }
    else {
        //..TODO: Log
        world = new World{ name };
        std::cout < "No tiles created for world '*" + name + "'.\n";
    }

    return world;
}
