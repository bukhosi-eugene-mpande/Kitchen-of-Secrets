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

Menu::~Menu(){}

std::unordered_map<int, std::string> Menu::getMenuItems()
{
    return menuItems;
}

void Menu::setMenuItems(std::unordered_map<int, std::string> menuItems)
{
    this->menuItems=menuItems;
}

int Menu::getNumberOnMenu()
{
    return numberOnMenu;
}

void Menu::setNumberOnMenu(int numberOnMenu)
{
    this->numberOnMenu=numberOnMenu;
}

std::string Menu::getitemName()
{
    return itemName;
}

void Menu::setItemName(std::string itemName)
{
    this->itemName=itemName;
}

int Menu::getNumOfItems()
{
    return numOfItems;
}

void Menu::setNumOfItems(int numOfItems)
{
    this->numOfItems=numOfItems;
}