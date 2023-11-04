#include "Menu.h"

Menu::Menu(std::unordered_map<int, std::string> menuItems)
{
    this->menuItems=menuItems;
}

Menu::Menu(const Menu& other)
{
    this->menuItems=other.menuItems;
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

