#ifndef MENUFACTORY_H
#define MENUFACTORY_H
#include <iostream>
#include "Menu.h"

class MenuFactory{
    public:
        virtual Menu* createMenu()=0;

};
#endif