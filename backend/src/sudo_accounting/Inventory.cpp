#include "Inventory.h"

Inventory::Inventory(std::unordered_map<std::string,int> inventory) {
    this->inventory = inventory;
}

Inventory::Inventory(const Inventory& other) {
    this->inventory = other.inventory;
}

Inventory::~Inventory() {
}

<<<<<<< HEAD
double Inventory::getTotalCost()
{
    return totalCost;
}

void Inventory::calculateTotalCost(std::unordered_map<std::string, int> ingredients) {
    totalCost = 0.0;
    for (const auto& ingredient : ingredients) {
        // You might have a price associated with each ingredient.
        // This is just an example; you need to adapt it to your data structure.
        double ingredientPrice = getIngredientPrice(ingredient.first);
        totalCost += ingredientPrice * ingredient.second;
    }
}

bool Inventory::requestIngredients(std::unordered_map<std::string, int> ingredients) {
    calculateTotalCost(ingredients);
=======
bool Inventory::requestIngredients(std::unordered_map<std::string,int> ingredients) {

>>>>>>> kitchen-Intergration
    for (auto const& ingredient : ingredients) {
        if (this->inventory.find(ingredient.first) == this->inventory.end() || this->inventory[ingredient.first] < ingredient.second) {
            return false;
        }
    }
    
    for (auto const& ingredient : ingredients) {
        if (this->inventory.find(ingredient.first) != this->inventory.end()) {
            this->inventory[ingredient.first] -= ingredient.second;
        }
    }
    return true;
}

std::unordered_map<std::string,int> Inventory::getInventory() const {
    return this->inventory;
}