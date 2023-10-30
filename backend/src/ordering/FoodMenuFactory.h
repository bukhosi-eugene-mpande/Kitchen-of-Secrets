#ifndef FOODMENUFACTORY_H
#define FOODMENUFACTORY_H
#include<iostream>
#include "MenuFactory.h"

class FoodMenuFcatory: public MenuFactory{
    protected:
        Menu* createMenu() override;
};
#endif