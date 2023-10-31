#include "Drinks.h"

Drinks::Drinks() :Menu("")
{
    std::cout<<"-----------------New Drinks Menu created.--------------"<<std::endl;
    std::cout<<std::endl;
}
void Drinks::setItems(std::map<std::string, double>items)
{
    this->items= this->items = {
        {"Spider Blood", 4.99},
        {"Ghost Blood", 3.99},
        {"Venom", 5.99},
        {"Bloody Mary", 6.99},
        {"Pumpkin Latter", 4.49},
        {"Witch's Brew", 5.49},
        {"Zombie Cocktail", 6.49},
        {"Poisedon", 7.99},
        {"Invisible Killer", 8.99},
        {"Scary Mocktail", 4.99}
    };
}

void Drinks::displayMenu()
{
    std::cout << "Drinks Menu:\n";
        for (const auto& item : getItems())
        {
            std::cout << "- " << item.first << ": $" << item.second << '\n';
}
}