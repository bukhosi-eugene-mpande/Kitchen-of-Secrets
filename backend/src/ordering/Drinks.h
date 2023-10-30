#ifndef DRINKS_H
#define DRINKS_H
#include <iostream>
#include "Menu.h"
#include<vector>
class Drinks: public Menu{
    public:
        Drinks();
        void setItems(std::vector<std::string> items) override;
        void displayMenu();
};
#endif