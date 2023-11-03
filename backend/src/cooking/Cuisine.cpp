#include "Cuisine.h"

Cuisine::Cuisine(double price,std::string name,std::string chef, std::unordered_map<std::string,int> ingredients) : Meal(price,name,chef,ingredients) {
}

Cuisine::Cuisine(const Cuisine& other) : Meal(other) { }

Cuisine::~Cuisine() { }