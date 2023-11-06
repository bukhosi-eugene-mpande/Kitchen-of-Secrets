#include "Inventory.h"

Inventory::Inventory() {
    this->inventory = {{"eye of newt", 1000},{"pasta", 1000},{"ground beef", 1000},{"blood garlic", 1000},{"ectoplasmic meat", 1000},{"monster patty", 1000},{"moonlit meatballs", 1000},{"witch's fingers", 1000},{"bandage crust", 1000},{"shrieking greens", 1000},{"goblin bits", 1000},{"spooky sausages", 1000},{"pumpkin rice", 1000},{"cauldron chicken", 1000},{"skeleton ribs", 1000},{"witch's potion", 1000},{"vampire blood vodka", 1000},{"zombie virus rum", 1000},{"mummy wrap rum", 1000},{"poison apple cider", 1000},{"ectoplasmic spirit", 1000},{"moonlit whiskey", 1000},{"pumpkin rum", 1000},{"goblin ale", 1000},{"haunting wine", 1000}};
}

Inventory::Inventory(const Inventory& other) {
    this->inventory = other.inventory;
}

Inventory::~Inventory() {
}

bool Inventory::requestIngredients(std::unordered_map<std::string, int> ingredients) {
    for (auto const& ingredient : ingredients) {
        if (this->inventory[ingredient.first] < ingredient.second) {
            return false;
        }
    }
    for (auto const& ingredient : ingredients) {
        this->inventory[ingredient.first] -= ingredient.second;
    }
    return true;
}

std::unordered_map<std::string,int> Inventory::getInventory() const {
    return this->inventory;
}