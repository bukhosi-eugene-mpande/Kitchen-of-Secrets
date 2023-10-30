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

void Menu::setName(std::string name)
{
    this->name=name;
}

std::vector<std::string> Menu::getItems()
{
    return items;
}


