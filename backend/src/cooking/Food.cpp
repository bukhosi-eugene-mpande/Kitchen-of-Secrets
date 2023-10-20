#include "Food.h"

Food::Food(double price,std::string name, std::unordered_map<std::string,int> ingredients) : MenuItem(price,name,ingredients) {

}

Food::~Food() {

}

Food::Food(const Food& other) : MenuItem(other) {

}

double Food::calculatePrice() {
    return this->mealPrice;
}

std::unordered_map<std::string,int> Food::calculateIngredients() {
    return this->mealIngredients;
}

std::shared_ptr<MenuItem> Food::clone() {
    return std::make_shared<Food>(*this);
}

void Food::prepare(){
    /**
     * @todo implement the prepare method
     * 
     */
}