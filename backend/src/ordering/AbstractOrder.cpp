#include "AbstractOrder.h"
#include "MenuItem.h"

AbstractOrder::AbstractOrder() {
    this->price = 0;
}

AbstractOrder::~AbstractOrder() {

}

std::unordered_map<std::string,int> AbstractOrder::getIngredients() const {
    return this->ingredients;
}

double AbstractOrder::getPrice() const {
    return this->price;
}

bool AbstractOrder::IsFinished() {
    for (auto meal : meals) {
        if (!meal->getIsPrepared()) {
            return false;
        }
    }
    return true;
}