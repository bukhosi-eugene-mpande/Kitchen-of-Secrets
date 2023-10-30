#include "Drinks.h"

Drinks::Drinks() :Menu("", std::vector<std::string>())
{
    std::cout<<"New Drinks Menu created."<<std::endl;
}
void Drinks::setItems(std::vector<std::string> items)
{
    this->items= {"Spider Blood", "Ghost Blood", "Venom", "Bloody Mary", "Pumpkin Latter", "Witch's Brew", "Zombie Cocktail", "Poisedon", "Invisible Killer", "Scary Mocktail"};
}

void Drinks::displayMenu()
{
    std::cout << "Drinks Menu:\n";
        for (const auto& item : getItems())
        {
            std::cout << "- " << item << '\n';
        }
}