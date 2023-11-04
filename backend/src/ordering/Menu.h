#ifndef Menu_H
#define Menu_H

#include <iostream>
#include <string>
#include <vector>
#include <map>  
#include <unordered_map>

class Menu{
    private:
        std::unordered_map<int, std::string> menuItems;
        
    public:
        Menu(std::unordered_map<int, std::string> menuItems);
        ~Menu();
        Menu(const Menu& other);
        std::unordered_map<int, std::string> getMenuItems();
        void setMenuItems(std::unordered_map<int, std::string> menuItems);

};
#endif