#include "Food.h"

Food::Food(std::shared_ptr<Engine> engine, double price, std::string name, std::unordered_map<std::string, int> ingredients) : MenuItem(engine, price, name, ingredients) {}

Food::~Food() {}

Food::Food(const Food& other) : MenuItem(other) {}

double Food::calculatePrice() {
    return this->mealPrice;
}

std::unordered_map<std::string,int> Food::calculateIngredients() {
    return this->mealIngredients;
}

std::shared_ptr<MenuItem> Food::clone() {
    return std::make_shared<Food>(*this);
}
