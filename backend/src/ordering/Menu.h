#ifndef MENU_H
#define MENU_H
#include <iostream>
//#include "Kitchen.h"
#include <vector>
#include <string>

class Menu{
    private:
        //Kitchen* kitchen;
        std::string name;
        std::vector<std::string> items;
    
    public:
        Menu(std::string name, std::vector<std::string> items);
        std::string getName();
        void setdName(std::string name);
        std::vector<std::string> getitems();
        //void setItems(std::vector<std::string> items);
        virtual void displayMenu()=0;
        virtual std::vector<std::string> getItems()=0;
};
#endif