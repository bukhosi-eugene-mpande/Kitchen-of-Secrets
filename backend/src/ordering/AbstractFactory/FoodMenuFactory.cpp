#include "FoodMenuFactory.h"
#include "Food.h"

Menu* FoodMenuFactory::createMenu()
{
    return new Food();
}