#pragma once
#include "Tile.h"
#include "Vector2.h"
#include "Grids/ObjectGrid.h"

class Tilemap : public ObjectGrid<Tile*> {

public:

    std::vector<Tile*>& Tiles() {
        return items;
    }

    void SnapAll() {
        for (auto& item : items) {
            Snap(item->position);
        }
    }
    
    Vector2 Dims() const {
        return Vector2::Zero;
    }
};