#include "DrinksMenuFactory.h"
#include "Drinks.h"

Menu* DrinksMenuFactory::createMenu()
{
    return new Drinks();
}