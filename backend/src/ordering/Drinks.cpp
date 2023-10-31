#include "Drinks.h"

Drinks::Drinks() :Menu("")
{
    
    std::cout<<std::endl;
}
void Drinks::setItems(std::map<std::string, double>items)
{
    this->items=items;
}


void Drinks::displayMenu()
{
    std::cout << "Drinks Menu:\n";
        for (const auto& item : getItems())
        {
            std::cout << "- " << item.first << ": R" << item.second << '\n';
    }
}