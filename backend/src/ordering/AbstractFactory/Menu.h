#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <map>
#include <string>

class Menu {
    protected:
        std::string name;
        std::map<std::string, double> items;
    public:
        Menu(std::string name);
        std::string getName();
        void setName(std::string name);
        virtual void setItems(std::map<std::string, double> items) = 0;
        virtual void displayMenu() = 0;
        std::map<std::string, double> getItems();
};
#endif