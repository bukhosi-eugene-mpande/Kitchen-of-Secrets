#include "FoodMenuFactory.h"
#include "Food.h"

Menu* FoodMenuFcatory::createMenu()
{
    return new Food();
}