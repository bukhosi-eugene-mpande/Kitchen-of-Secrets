#ifndef DRINKSMENUFACTORY_H
#define DRINKSMENUFACTORY_H
#include<iostream>
#include "MenuFactory.h"

class DrinksMenuFactory: public MenuFactory{
    public:
        Menu* createMenu() override;
};
#endif