#include <gtest/gtest.h>
#include <memory>
#include "Meal.h"
#include "Meal.cpp"

TEST(MealTest, ConstructorTest) {
    std::unordered_map<std::string, int> ingredients = {{"salt", 2}, {"pepper", 1}, {"garlic", 3}};
    Meal meal(10.99, "Spaghetti Carbonara", "Gordon Ramsay", ingredients);
    EXPECT_EQ(meal.getPrice(), 10.99);
    EXPECT_EQ(meal.getName(), "Spaghetti Carbonara");
    EXPECT_EQ(meal.getChef(), "Gordon Ramsay");
    EXPECT_EQ(meal.getIngredients(), ingredients);

    std::unordered_map<std::string, int> ingredients2 = {{"basil", 1}, {"pine nuts", 2}, {"garlic", 3}};
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(12.99, "Pesto Pasta", "Jamie Oliver", ingredients2);
    EXPECT_EQ(meal2->getPrice(), 12.99);
    EXPECT_EQ(meal2->getName(), "Pesto Pasta");
    EXPECT_EQ(meal2->getChef(), "Jamie Oliver");
    EXPECT_EQ(meal2->getIngredients(), ingredients2);
    
}

TEST(MealTest, GettersAndSettersTest) {
    std::unordered_map<std::string, int> ingredients = {{"salt", 2}, {"pepper", 1}, {"garlic", 3}};
    Meal meal(10.99, "Spaghetti Carbonara", "Gordon Ramsay", ingredients);
    EXPECT_EQ(meal.getPrice(), 10.99);
    EXPECT_EQ(meal.getName(), "Spaghetti Carbonara");
    EXPECT_EQ(meal.getChef(), "Gordon Ramsay");
    EXPECT_EQ(meal.getIngredients(), ingredients);

    meal.setPrice(12.99);
    meal.setName("Pesto Pasta");
    meal.setChef("Jamie Oliver");
    std::unordered_map<std::string, int> newIngredients = {{"basil", 1}, {"pine nuts", 2}, {"garlic", 3}};
    meal.setIngredients(newIngredients);

    EXPECT_EQ(meal.getPrice(), 12.99);
    EXPECT_EQ(meal.getName(), "Pesto Pasta");
    EXPECT_EQ(meal.getChef(), "Jamie Oliver");
    EXPECT_EQ(meal.getIngredients(), newIngredients);
}