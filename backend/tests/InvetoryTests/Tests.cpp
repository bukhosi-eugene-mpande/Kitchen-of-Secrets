#include "gtest/gtest.h"

#include "../includes/include_all.h"
#include "../includes/include_all.cpp"

TEST(InventoryTest, InventorySanityTests) {
    std::shared_ptr<Inventory> testInventory = std::make_shared<Inventory>();

    std::unordered_map<std::string, int> ingredients = {{"flour", 2}, {"sugar", 3}, {"eggs", 1}};

    std::unordered_map<std::string, int> ingredients2 = {{"eye of newt", 500}};

    EXPECT_FALSE(testInventory->requestIngredients(ingredients));
    
    EXPECT_EQ(testInventory->getInventory()["eye of newt"],1000);

    EXPECT_TRUE(testInventory->requestIngredients(ingredients2));

    EXPECT_EQ(testInventory->getInventory()["eye of newt"],500);

}
