#pragma once
#include "Tile.h"
#include "Vector2.h"
#include <vector>

class Tilemap {
  public:
    std::vector<Tile> Tiles;
    
    int Size() const {
      return Tiles.size();
    }
    Vector2 Dims() const{
      return Vector2::Zero;
    }
}