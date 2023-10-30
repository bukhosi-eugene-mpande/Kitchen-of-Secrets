#ifndef MENU_H
#define MENU_H
#include <iostream>
//#include "Kitchen.h"
#include <map>
#include <string>

class Menu{
    protected:
        //Kitchen* kitchen;
        std::string name;
        std::map<std::string, double> items;
    
    public:
        Menu(std::string name);
        std::string getName();
        void setName(std::string name);
        //std::vector<std::string> getitems();
        virtual void setItems(std::map<std::string, double> items)=0;
        virtual void displayMenu()=0;
        std::map<std::string, double> getItems();
};
#endif