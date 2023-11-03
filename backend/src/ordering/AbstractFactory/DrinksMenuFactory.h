#ifndef DRINKS_MENU_FACTORY_H
#define DRINKS_MENU_FACTORY_H
#include "MenuFactory.h"
#include<iostream>

class DrinksMenuFactory: public MenuFactory {
    public:
        std::shared_ptr<Menu> createMenu() override;
};
#endif