#include <gtest/gtest.h>
#include <memory>
#include "Kitchen.h"
#include "Kitchen.cpp"

#include "Meal.h"
#include "Meal.cpp"

TEST(KitchenTest,ConstructorTest){  
    std::unordered_map<std::string, int> ingredients1 = {{"basil", 1}, {"pine nuts", 2}, {"garlic", 3}};
    std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(12.99, "Pesto Pasta", "Cook", ingredients1);

    std::unordered_map<std::string, int> ingredients2 = {{"salt", 2}, {"pepper", 1}, {"garlic", 3}};
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(10.99, "Spaghetti Carbonara", "Baker", ingredients2);

    std::unordered_map<std::string, int> ingredients3 = {{"lemon", 2}, {"pepper", 1}, {"wings", 3}};
    std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(10.99, "Lemon pepper wings", "Grill chef", ingredients3);
    
    //vector of meals
    std::vector <std::shared_ptr<Meal>> meals = {meal1, meal2, meal3};

    //shared_ptr<Management> management
    std::shared_ptr<Management> management = std::make_shared<Management>();
    
    //shared_ptr<HeadChef> headChef
    std::shared_ptr<HeadChef> headChef = std::make_shared<HeadChef>(management);

    //shared_ptr<DeputyHeadChef> deputyHeadChef
    std::shared_ptr<DeputyHeadChef> deputyHeadChef = std::make_shared<DeputyHeadChef>(management);

    //kitchen
    Kitchen kitchen(management, headChef, deputyHeadChef, meals);

    //check magament
    EXPECT_EQ(kitchen.getManagement(), management);

    //check headChef
    EXPECT_EQ(kitchen.getHeadChef(), headChef);

    //check deputyHeadChef
    EXPECT_EQ(kitchen.getDeputyHeadChef(), deputyHeadChef);

}