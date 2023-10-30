// Main.cpp
#include "FoodMenuFactory.h"
#include "DrinksMenuFactory.h"

int main() {
    FoodMenuFactory foodFactory;
    DrinksMenuFactory drinksFactory;

    Menu* foodMenu = foodFactory.createMenu();
    foodMenu->setItems({});
    foodMenu->displayMenu();

    Menu* drinksMenu = drinksFactory.createMenu();
    drinksMenu->setItems({});
    drinksMenu->displayMenu();

    delete foodMenu;
    delete drinksMenu;

    return 0;
}