#pragma once
#include "Grid.h"
#include <vector>

template<typename T>
class ObjectGrid : public Grid{
  private:
    std::vector<T*> items;
  
  public:
    ObjectGrid() : Grid() {}
  
  
    T& Add(T* object) const {
      //..TODO: Check if contains
      
      items.push_back(object);
      return *object;
    }
    
    bool Remove(T* object){
      //..TODO: check & remove
      return true;
    }
    
  
}