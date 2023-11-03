#include "FoodMenuFactory.h"
#include "Food.h"

std::shared_ptr<Menu> FoodMenuFactory::createMenu() {
    return std::make_shared<Food>();
}

FoodMenuFactory::FoodMenuFactory(std::shared_ptr<Engine> engine) : MenuFactory(engine) {}

FoodMenuFactory::~FoodMenuFactory() {}