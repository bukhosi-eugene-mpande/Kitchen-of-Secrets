#include "BeverageInventory.h"

BeverageInventory::BeverageInventory()
{
    inventory["Soda"] = 10;
    inventory["Tea"] = 10;
    inventory["Coffee"] = 10;
    inventory["Juice"] = 10;
    inventory["Milk"] = 10;
}

void BeverageInventory::update(std::unordered_map<std::string, int> items)
{
    for (auto item : items)
    {
        inventory[item.first] -= item.second;
    }
}