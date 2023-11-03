// #include <gtest/gtest.h>
// #include <memory>

// #include "../includes/include_all.h"

// TEST(BeverageTest, ConstructorTest) {
//     std::unordered_map<std::string, int> ingredients = {{"water", 1}, {"sugar", 2}};
//     Beverage beverage(false, 2.5, "Lemonade", ingredients);
//     EXPECT_EQ(beverage.calculatePrice(), 2.5);
//     EXPECT_EQ(beverage.getName(), "Lemonade");
//     EXPECT_EQ(beverage.calculateIngredients(), ingredients);
//     EXPECT_FALSE(beverage.getIsAlcoholic());
// }

// TEST(BeverageTest, AlcoholicTest) {
//     std::unordered_map<std::string, int> ingredients = {{"water", 1}, {"sugar", 2},{"vodka", 1}};
//     Beverage beverage(true, 4.5, "Spiked Lemonade", ingredients);
//     EXPECT_EQ(beverage.calculatePrice(), 4.5);
//     EXPECT_EQ(beverage.getName(), "Spiked Lemonade");
//     EXPECT_EQ(beverage.calculateIngredients(), ingredients);
//     EXPECT_TRUE(beverage.getIsAlcoholic());
    
// }