#include <gtest/gtest.h>
#include <memory>

#include "../includes/include_all.h"
#include "../includes/include_all.cpp"

TEST(GameRunnerTst, RunningGameTest) {
    GameRunner* gameRunner =  new GameRunner();

    gameRunner->requestReservation("Private Section");

    std::unordered_map<int,std::string> foodMenu = gameRunner->getFoodMenu();

    std::unordered_map<int,std::string> beverageMenu = gameRunner->getBeverageMenu();

    gameRunner->sendBeverageOrder({{"Witches' Brew Punch",1},{"Vampire's Kiss Martini",2}});

    gameRunner->sendFoodOrder({{"Vampire Garlic Bread",5},{"Werewolf Bites",4},{"Screaming Salad",3},{"Cursed Cauldron Curry",2}});

    gameRunner->changeMood();

    gameRunner->doRoundsChef();

    std::string payment = gameRunner->payment("cash", 100);

    EXPECT_EQ(payment, "Cash Payment successful");

}
