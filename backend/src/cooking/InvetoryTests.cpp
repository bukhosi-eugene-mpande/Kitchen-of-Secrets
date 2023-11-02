#include "gtest/gtest.h"

#include "Inventory.h"
#include "Inventory.cpp"

TEST(InventoryTest, RequestIngredientsReturnsTrueWhenEnoughIngredients) {
    std::unordered_map<std::string, int> inventory = {{"flour", 5}, {"sugar", 10}, {"eggs", 6}};
    Inventory testInventory(inventory);
    std::unordered_map<std::string, int> ingredients = {{"flour", 2}, {"sugar", 3}, {"eggs", 1}};
    EXPECT_TRUE(testInventory.requestIngredients(ingredients));
    EXPECT_EQ(testInventory.getInventory()["flour"], 3);
    EXPECT_EQ(testInventory.getInventory()["sugar"], 7);
    EXPECT_EQ(testInventory.getInventory()["eggs"], 5);
}

TEST(InventoryTest, RequestIngredientsReturnsFalseWhenNotEnoughIngredients) {
    std::unordered_map<std::string, int> inventory = {{"flour", 5}, {"sugar", 10}, {"eggs", 6}};
    Inventory testInventory(inventory);
    std::unordered_map<std::string, int> ingredients = {{"flour", 2}, {"sugar", 3}, {"eggs", 10}};
    EXPECT_FALSE(testInventory.requestIngredients(ingredients));
    EXPECT_EQ(testInventory.getInventory()["flour"], 5);
    EXPECT_EQ(testInventory.getInventory()["sugar"], 10);
    EXPECT_EQ(testInventory.getInventory()["eggs"], 6);
}

TEST(InventoryTest, RequestIngredientsReturnsTrueWhenEmptyIngredients) {
    std::unordered_map<std::string, int> inventory = {{"flour", 5}, {"sugar", 10}, {"eggs", 6}};
    Inventory testInventory(inventory);
    std::unordered_map<std::string, int> ingredients;
    EXPECT_TRUE(testInventory.requestIngredients(ingredients));
    EXPECT_EQ(testInventory.getInventory()["flour"], 5);
    EXPECT_EQ(testInventory.getInventory()["sugar"], 10);
    EXPECT_EQ(testInventory.getInventory()["eggs"], 6);
}