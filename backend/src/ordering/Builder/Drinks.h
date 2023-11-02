#ifndef DRINKS_H
#define DRINKS_H
#include <iostream>
#include "Menu.h"
#include<map>
class Drinks: public Menu{
    public:
        Drinks();
        void setItems(std::map<std::string, double> items) override;
        void displayMenu();
        
};
#endif