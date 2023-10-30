#include "HalloweenOrderBuidler.h"
#include "Menu.h"

void HalloweenOrderBuilder::addDrink()
{
    Menu* drinksMenu=drinksMenuFactory.createMenu();
    this->order->items.insert(drinksMenu->getItems().begin(), drinksMenu->getItems().end());
    delete drinksMenu;
}

void HalloweenOrderBuilder::addFood()
{
    Menu* foodMenu=foodMenuFactory.createMenu();
    this->order->items.insert(foodMenu->getItems().begin(), foodMenu->getItems().end());
    delete foodMenu;
}