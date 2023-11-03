#include "Menu.h"

Menu::Menu(std::unordered_map<int, std::string> menuItems, int numberOnMenu, std::string itemName,int numOfItems)
{
    this->menuItems=menuItems;
    this->numberOnMenu=numberOnMenu;
    this->itemName=itemName;
    this->numOfItems=numOfItems;
}

Menu::Menu(const Menu& other)
{
    this->menuItems=other.menuItems;
    this->numberOnMenu=other.numberOnMenu;
    this->itemName=other.itemName;
    this->numOfItems=other.numOfItems;
}