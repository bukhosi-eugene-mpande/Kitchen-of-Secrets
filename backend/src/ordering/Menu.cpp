#include "Menu.h"

Menu::Menu(std::string name, std::vector<std::string> items)
{
    this->name=name;
    this->items=items;
}

std::string Menu::getName()
{
    return name;
}

void Menu::setdName(std::string name)
{
    this->name=name;
}


