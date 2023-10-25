#ifndef MENUFACTORY_H
#define MENUFACTORY_H
#include <iostream>
#include "Menu.h"
class MenuFactory{
    private:
        Menu* createDrinkMenu();
        Menu* createFoodMenu();

};
#endif