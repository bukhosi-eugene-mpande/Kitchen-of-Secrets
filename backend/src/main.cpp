#include <iostream>

#include "../tests/includes/include_all.h"
#include "../tests/includes/include_all.cpp"

int main()
{
    GameRunner *gameRunner = new GameRunner();

    gameRunner->requestReservation("Private Section");

    std::unordered_map<int, std::string> foodMenu = gameRunner->getFoodMenu();

    std::unordered_map<int, std::string> beverageMenu = gameRunner->getBeverageMenu();

    gameRunner->sendBeverageOrder({{"Witches' Brew Punch", 1}, {"Vampire's Kiss Martini", 2}});

    gameRunner->sendFoodOrder({{"Vampire Garlic Bread", 5}, {"Werewolf Bites", 4}, {"Screaming Salad", 3}, {"Cursed Cauldron Curry", 2}});

    gameRunner->changeMood();

    gameRunner->doRoundsChef();

    std::string payment = gameRunner->payment("cash", 100);

    std::cout << payment << std::endl;

    return 0;
}