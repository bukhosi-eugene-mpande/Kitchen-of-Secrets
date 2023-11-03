#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include "Menu.h"

class Food: public Menu{
    public:
        Food();
        void setItems(std::map<std::string, double> items) override;
        void displayMenu();
};
#endif