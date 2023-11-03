#include <gtest/gtest.h>
#include <memory>
#include "../includes/include_all.h" 

TEST(MenuTest, ConstructorTest)
{
    // Create an instance of Menu using the constructor
    std::unordered_map<int, std::string> menuItems = {{1, "Item1"}, {2, "Item2"}};
    Menu menu(menuItems, 2, "MenuName", 10);

    // Verify that the properties of the Menu object are set correctly
    EXPECT_EQ(menu.getMenuItems(), menuItems);
    EXPECT_EQ(menu.getNumberOnMenu(), 2);
    EXPECT_EQ(menu.getItemName(), "MenuName");
    EXPECT_EQ(menu.getNumOfItems(), 10);
}