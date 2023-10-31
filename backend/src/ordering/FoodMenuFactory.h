#ifndef FOODMENUFACTORY_H
#define FOODMENUFACTORY_H
#include<iostream>
#include "MenuFactory.h"

class FoodMenuFactory: public MenuFactory{
    public:
        Menu* createMenu() override;
};
#endif