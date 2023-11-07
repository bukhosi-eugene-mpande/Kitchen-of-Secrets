#include "Drink.h"

Drink::Drink(bool isAlcoholic,double price,std::string name,std::string chef, std::unordered_map<std::string,int> ingredients) : Meal(price,name,chef,ingredients) {
    this->isAlcoholic = isAlcoholic;
}

Drink::Drink(const Drink& other) : Meal(other) {
    this->isAlcoholic = other.getIsAlcoholic();
}

Drink::~Drink() {
}
