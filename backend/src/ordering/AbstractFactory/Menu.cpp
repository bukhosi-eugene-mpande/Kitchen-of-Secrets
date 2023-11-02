#include "Menu.h"

Menu::Menu(std::string name)
{
    this->name=name;
}

std::string Menu::getName()
{
    return name;
}

void Menu::setName(std::string name)
{
    this->name=name;
}

std::map<std::string, double>  Menu::getItems()
{
    return items;
}


