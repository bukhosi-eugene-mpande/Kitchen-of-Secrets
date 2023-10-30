#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "Menu.h"

class Food: public Menu{
    public:
        std::vector<std::string> getItems() override;
        void displayMenu();
};
#endif