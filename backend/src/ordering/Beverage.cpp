#include "Beverage.h"

Beverage::Beverage(const Beverage& other) : MenuItem(other) {
    this->isAlcoholic = other.isAlcoholic;
}

Beverage::Beverage(bool isAlcoholic, double price, std::string name, std::unordered_map<std::string, int> ingredients) : MenuItem(price, name, ingredients) {
    this->isAlcoholic = isAlcoholic;
}

Beverage::~Beverage() {}

double Beverage::calculatePrice() {
    return this->mealPrice;
}

std::unordered_map<std::string,int> Beverage::calculateIngredients() {
    return this->mealIngredients;
}

std::shared_ptr<MenuItem> Beverage::clone() {
    return std::make_shared<Beverage>(*this);
}

bool Beverage::getIsAlcoholic() const {
    return this->isAlcoholic;
}