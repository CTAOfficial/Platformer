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
    
    Tile& Add(Tile* tile) const {
      // ..TODO: check if contains
      Tiles.push_back(tile);
      return *tile;
      }
    
    bool Remove(Tile* tile){
      //..TODO: Remove tile
      return true;
    }
}