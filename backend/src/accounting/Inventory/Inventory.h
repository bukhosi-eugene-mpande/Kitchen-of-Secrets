#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <unordered_map>

class Inventory
{
protected:
    std::unordered_map<std::string, int> inventory;

public:
    virtual void update() = 0;
};

#endif