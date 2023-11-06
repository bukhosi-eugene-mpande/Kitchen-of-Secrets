#include "MenuItem.h"


MenuItem::MenuItem(double price, std::string name, std::unordered_map<std::string, int> ingredients){
    this->name = name;
    this->mealIngredients = ingredients;
    this->mealPrice = price;
    this->isPrepared = false;
}

MenuItem::~MenuItem() {}

MenuItem::MenuItem(const MenuItem &other) {
    this->name = other.name;
    this->mealIngredients = other.mealIngredients ;
    this->mealPrice = other.mealPrice;
}

std::unordered_map<std::string,int> MenuItem::getMealIngredients() const {
    return this->mealIngredients;
}

std::string MenuItem::getName() const {
    return this->name;
}

double MenuItem::getMealPrice() const{
    return this->mealPrice;
}

void MenuItem::prepare(){
    this->isPrepared = true;
}

bool MenuItem::getIsPrepared() const{
    return this->isPrepared;
}
