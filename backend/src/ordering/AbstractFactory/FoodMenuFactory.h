#ifndef FOOD_MENU_FACTORY_H
#define FOOD_MENU_FACTORY_H

#include "MenuFactory.h"

#include<iostream>

class FoodMenuFactory: public MenuFactory {
    public:
        FoodMenuFactory(std::shared_ptr<Engine> engine);
        ~FoodMenuFactory();
        std::shared_ptr<Menu> createMenu();
};
#endif