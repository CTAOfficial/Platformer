#pragma once
#include "Entities/GameObject.h"

class Sprite;
class Texture;

class Tile : public GameObject {
protected:
    using GameObject::GameObject;

public:
    Tile(Texture* texture);
    Tile(Texture* texture, Vector2 pos);

    Sprite* sprite;


};