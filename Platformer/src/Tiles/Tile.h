#pragma once
#include "Entities/GameObject.h"

class Sprite;
class Texture;

class Tile : public GameObject {
protected:
    using GameObject::GameObject;

public:
    Tile(Sprite* sprite);
    Tile(Sprite* sprite, Vector2 pos);
    Tile(Texture* texture);
    Tile(Texture* texture, Vector2 pos);

    Sprite* sprite = nullptr;


};