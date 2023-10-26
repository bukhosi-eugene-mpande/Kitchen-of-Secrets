#include "FoodInventory.h"

FoodInventory::FoodInventory()
{
    inventory["Burger"] = 10;
    inventory["Fries"] = 10;
    inventory["Salad"] = 10;
    inventory["Wings"] = 10;
    inventory["Pizza"] = 10;
}

void FoodInventory::update(std::unordered_map<std::string, int> items)
{
    for (auto item : items)
    {
        inventory[item.first] -= item.second;
    }
}