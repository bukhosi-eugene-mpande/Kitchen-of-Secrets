#ifndef MENU_H
#define MENU_H
#include <iostream>
//#include "Kitchen.h"
#include <vector>
#include <string>

class Menu{
    protected:
        //Kitchen* kitchen;
        std::string name;
        std::vector<std::string> items;
    
    public:
        Menu(std::string name, std::vector<std::string> items);
        std::string getName();
        void setName(std::string name);
        //std::vector<std::string> getitems();
        virtual void setItems(std::vector<std::string> items)=0;
        virtual void displayMenu()=0;
        std::vector<std::string> getItems();
};
#endif