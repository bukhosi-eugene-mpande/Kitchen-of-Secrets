#include "DrinksMenuFactory.h"
#include "Drinks.h"

Menu* DrinksMenuFcatory::createMenu()
{
    return new Drinks();
}