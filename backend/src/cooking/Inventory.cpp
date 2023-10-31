#include "Inventory.h"

Inventory::Inventory(std::unordered_map<std::string,int> inventory) {
    this->inventory = inventory;
}

Inventory::Inventory(const Inventory& other) {
    this->inventory = other.inventory;
}

Inventory::~Inventory() {
}

bool Inventory::requestIngredients(std::unordered_map<std::string,int> ingredients) {
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