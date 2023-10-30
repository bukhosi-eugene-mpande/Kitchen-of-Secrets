#ifndef DRINKSMENUFACTORY_H
#define DRINKSMENUFACTORY_H
#include<iostream>
#include "MenuFactory.h"

class DrinksMenuFcatory: public MenuFactory{
    protected:
        Menu* createMenu() override;
};
#endif