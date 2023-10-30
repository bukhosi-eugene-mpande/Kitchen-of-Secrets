#include "Drinks.h"

Drinks::Drinks() :Menu("", std::vector<std::string>())
{
    std::cout<<"New Drinks Menu created."<<std::endl;
}
std::vector<std::string> Drinks::getItems()
{
    return {"Spider Blood", "Ghost Blood", "Venom", "Bloody Mary", "Pumpkin Latter", "Witch's Brew", "Zombie Cocktail", "Poisedon", "Invisible Killer", "Scary Mocktail"};
}

void Drinks::displayMenu()
{
    std::cout << "Drinks Menu:\n";
        for (const auto& item : getItems())
        {
            std::cout << "- " << item << '\n';
        }
}