#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "Kitchen.h"
#include <vector>
#include <string>
class Menu{
    private:
        Kitchen* kitchen;
        std::string name;
        std::vector<std::string> items;
    
    public:
        Menu(int, std::string);
        std::string getName();
        void setdName(std::string name);
        std::vector<std::string> getitems();
        void setItems(std::vector<std::string> items);
    
    protected:
       virtual void displayMenu()=0;
};
#endif