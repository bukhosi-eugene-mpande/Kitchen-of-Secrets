#ifndef Menu_H
#define Menu_H

#include <iostream>
#include <string>
#include <vector>
#include <map>  
#include <unordered_map>

#include "Order.h"
#include "MenuItem.h"
#include "Menu.h"

class Menu{
    private:
        std::unordered_map<int, std::string> menuItems;
        int numberOnMenu;
        std::string itemName;
        int numOfItems;
    public:
        Menu(std::unordered_map<int, std::string> menuItems, int numberOnMenu, std::string itemName,int numOfItems);
        ~Menu();
        Menu(const Menu& other);
        std::unordered_map<int, std::string> getMenuItems();
        void setMenuItems(std::unordered_map<int, std::string> menuItems);
        int getNumberOnMenu();
        void setNumberOnMenu(int numberOnMenu);
        std::string getitemName();
        void setItemName(std::string);
        int getNumOfItems();
        void setNumOfItems(int numOfItems);
};
#endif