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

TEST(FoodTest, CloneTest) {
    std::unordered_map<std::string, int> ingredients = {{"flour", 2}, {"sugar", 1}, {"eggs", 3}};
    Food originalFood(10.99, "Pancakes", ingredients);
    
    // Clone the originalFood
    std::shared_ptr<MenuItem> clonedFood = originalFood.clone();

    // Check if the clone is an instance of the Food class
    std::shared_ptr<Food> foodClone = std::dynamic_pointer_cast<Food>(clonedFood);
    ASSERT_NE(foodClone, nullptr);

    // Check the price and name of the clone
    EXPECT_EQ(foodClone->calculatePrice(), originalFood.calculatePrice());
    EXPECT_EQ(foodClone->getName(), originalFood.getName());

    // Check the ingredients of the clone
    EXPECT_EQ(foodClone->calculateIngredients(), originalFood.calculateIngredients());
}
