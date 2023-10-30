#ifndef MENUFACTORY_H
#define MENUFACTORY_H
#include <iostream>
#include "Menu.h"

class MenuFactory{
    private:
        virtual Menu* createMenu()=0;

};
#endif