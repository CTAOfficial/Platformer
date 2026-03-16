#pragma once
#include "Grid.h"
#include <algorithm>
#include <vector>

template<typename T>
class ObjectGrid : public Grid {
protected:
    std::vector<T> items;

public:
    ObjectGrid() : Grid() {}
    ObjectGrid(T array[]) : ObjectGrid() {
        for (auto& item : array) {
            Add(item);
        }
    }
    ~ObjectGrid() {
        for (auto& item : items) {
            Remove(item);
            delete item;
        }
    }

    virtual bool TryAdd(T object) {
        if (Contains(object)) { return false; }

        Add(object);
        return true;
    }

    virtual T Add(T object) {
        items.push_back(object);
        return object;
    }

    virtual bool Remove(T object) {
        if (!Contains(object)) { return false; }

        std::erase(items, object);
        return true;
    }

    virtual bool Contains(T object) {
        for (auto& item : items) {
            if (item == object) {
                return true;
            }
        }

        return false;
    }

    int Size() const {
        return items.size();
    }
};