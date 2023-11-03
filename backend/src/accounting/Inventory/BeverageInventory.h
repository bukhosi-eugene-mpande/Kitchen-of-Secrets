#ifndef BEVERAGEINVENTORY_H
#define BEVERAGEINVENTORY_H

#include <string>
#include <unordered_map>

#include "Inventory.h"

class BeverageInventory : public Inventory
{
public:
    BeverageInventory();

    void update(std::unordered_map<std::string, int> items);
};

#endif