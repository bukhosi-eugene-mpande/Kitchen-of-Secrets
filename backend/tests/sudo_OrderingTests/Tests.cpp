#include <gtest/gtest.h>
#include <memory>

#include "../includes/customercare_all.cpp"
#include "../includes/reservation_all.cpp"
#include "../includes/inventory_all.cpp"
#include "../includes/ordering_all.cpp"
#include "../includes/cooking_all.cpp"
#include "../includes/management_all.cpp"

TEST(MenuTests, MenuConstructorTest){
    //shared_ptr<Management> management
    std::shared_ptr<Management> management = std::make_shared<Management>();

    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management.get());

    std::shared_ptr<Menu> Bevmenu = std::make_shared<Menu>(kitchen->getDrinksMenu());

    std::shared_ptr<Menu> Foodmenu = std::make_shared<Menu>(kitchen->getCuisineMenu());

    EXPECT_EQ(Bevmenu->getMenuItems().size(), 10);
    EXPECT_EQ(Foodmenu->getMenuItems().size(), 15);
    
}





