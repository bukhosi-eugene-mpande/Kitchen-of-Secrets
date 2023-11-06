#include "Meal.h"

Meal::Meal(double price,std::string name,std::string chef, std::unordered_map<std::string,int> ingredients) {
    this->price = price;
    this->name = name;
    this->ingredients = ingredients;
    this->chef = chef;
}

Meal::Meal(const Meal& other) {
    this->price = other.getPrice();
    this->name = other.getName();
    this->ingredients = other.getIngredients();
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

void Meal::setName(std::string name) {
    this->name = name;
}

void Meal::setChef(std::string chef) {
    this->chef = chef;
}

void Meal::setIngredients(std::unordered_map<std::string,int> ingredients) {
    this->ingredients = ingredients;
}

void Meal::setPrice(double price) {
    this->price = price;
}

bool Meal::getIsAlcoholic() const {
    return this->isAlcoholic;
}


