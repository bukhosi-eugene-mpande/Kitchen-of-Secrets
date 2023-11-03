#ifndef MENUFACTORY_H
#define MENUFACTORY_H

#include "Menu.h"
#include "GameComponent.h"

#include <iostream>

class MenuFactory : public GameComponent{
    public:
        MenuFactory(std::shared_ptr<Engine> engine);
        ~MenuFactory();
        virtual std::shared_ptr<Menu> createMenu() = 0;

};
#endif