#include "gtest/gtest.h"

//includes for Food.h
#include "Food.h"
#include "Food.cpp"

//extra includes
#include "AbstractOrder.cpp"
#include "MenuItem.cpp"

TEST(FoodTest, ConstructorTest) {
    std::unordered_map<std::string, int> ingredients = {{"flour", 2}, {"sugar", 1}, {"eggs", 3}};
    Food food(10.99, "Pancakes", ingredients);
    EXPECT_EQ(food.calculatePrice(), 10.99);
    EXPECT_EQ(food.getName(), "Pancakes");
    EXPECT_EQ(food.calculateIngredients(), ingredients);
}