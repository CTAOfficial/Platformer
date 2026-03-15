#pragma once
#include "Vector2.h"

struct Grid{
  public:
    Grid(){}
  
    float Spacing = 0;
  
    void Snap(Vector2 vec);
}