#pragma once
#include "Entities/GameObject.h"

class Sprite;
class Texture;

class Tile : public GameObject {
public:
    Tile(Texture* texture);

    Sprite* sprite;


};