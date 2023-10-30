#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "Menu.h"

class Food: public Menu{
    public:
        Food();
        void setItems(std::vector<std::string> items) override;
        void displayMenu();
};
#endif