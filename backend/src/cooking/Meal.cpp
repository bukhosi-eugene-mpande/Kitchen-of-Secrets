#include "Meal.h"

Meal::Meal(double price,std::string name,std::string chef, std::unordered_map<std::string,int> ingredients) {
    this->price = price;
    this->name = name;
    this->ingredients = ingredients;
    this->chef = chef;
}

Meal::Meal(const Meal& other) {
    this->price = other.price;
    this->name = other.name;
    this->ingredients = other.ingredients;
}

Meal::~Meal() {
}

std::string Meal::getName() const {
    return this->name;
}

std::string Meal::getChef() const {
    return this->chef;
}

std::unordered_map<std::string,int> Meal::getIngredients() const {
    return this->ingredients;
}

double Meal::getPrice() const {
    return this->price;
}
