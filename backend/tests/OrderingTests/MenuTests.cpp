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

TEST(MenuTest, GettersAndSettersTest)
{
    // Create an instance of Menu
    std::unordered_map<int, std::string> menuItems = {{1, "Item1"}, {2, "Item2"}};
    Menu menu(menuItems, 2, "MenuName", 10);

    // Test the getters and setters
    EXPECT_EQ(menu.getMenuItems(), menuItems);
    EXPECT_EQ(menu.getNumberOnMenu(), 2);
    EXPECT_EQ(menu.getItemName(), "MenuName");
    EXPECT_EQ(menu.getNumOfItems(), 10);

    // Modify the menu properties using setters
    std::unordered_map<int, std::string> newMenuItems = {{3, "Item3"}, {4, "Item4"}};
    menu.setMenuItems(newMenuItems);
    menu.setNumberOnMenu(4);
    menu.setItemName("NewMenuName");
    menu.setNumOfItems(20);
     // Verify that the properties have been updated
    EXPECT_EQ(menu.getMenuItems(), newMenuItems);
    EXPECT_EQ(menu.getNumberOnMenu(), 4);
    EXPECT_EQ(menu.getItemName(), "NewMenuName");
    EXPECT_EQ(menu.getNumOfItems(), 20);
}