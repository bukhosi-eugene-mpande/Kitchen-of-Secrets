#ifndef FOODINVENTORY_H
#define FOODINVENTORY_H

#include <string>
#include <unordered_map>

#include "Inventory.h"

class FoodInventory : public Inventory
{
public:
    FoodInventory();

    void update(std::unordered_map<std::string, int> items);
};

#endif