#include <gtest/gtest.h>
#include <memory>

#include "../includes/customercare_all.cpp"
#include "../includes/reservation_all.cpp"
#include "../includes/inventory_all.cpp"
#include "../includes/ordering_all.cpp"
#include "../includes/cooking_all.cpp"
#include "../includes/management_all.cpp"

TEST(MenuTest, MenuConstructorTest){
    //shared_ptr<Management> management
    std::shared_ptr<Management> management = std::make_shared<Management>();

    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management.get());

    std::shared_ptr<Menu> Bevmenu = std::make_shared<Menu>(kitchen->getDrinksMenu());

    std::shared_ptr<Menu> Foodmenu = std::make_shared<Menu>(kitchen->getCuisineMenu());

    EXPECT_EQ(Bevmenu->getMenuItems().size(), 10);
    EXPECT_EQ(Foodmenu->getMenuItems().size(), 15);

}

TEST(OrderTests, OrderConstructorTest){
    std::shared_ptr<Management> management = std::make_shared<Management>();
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management.get());
    management->setKitchen(kitchen);
    Section* section = management->getGeneralSection().get();
    std::shared_ptr<Waiter> waiterPtr = std::make_shared<Waiter>(section, management.get());

    // Create instances of Food and Beverages directly
    std::unordered_map<std::string, int> foodIngredients = {{"flour", 2}, {"sugar", 1}};
    std::unordered_map<std::string, int> beverageIngredients = {{"water", 1}, {"vodka", 2},{"lemonade", 3}};

    std::shared_ptr<MenuItem> foodItem = std::make_shared<Food>(10.99, "Pancakes", foodIngredients);
    std::shared_ptr<MenuItem> beverageItem = std::make_shared<Beverage>(true,8.50, "Vodka Lemonade", beverageIngredients);

    std::vector<std::shared_ptr<MenuItem>> items = {foodItem, beverageItem};

    std::shared_ptr<Table> table = section->getTables()[0];

    std::shared_ptr<Order> order = std::make_shared<Order>(table,items, waiterPtr.get());

    // Check if the table number, waiter, and meals are set correctly
    EXPECT_EQ(order->getTable(), table);
    EXPECT_EQ(order->getWaiter(), waiterPtr.get());
    EXPECT_EQ(order->getMeals(), items);
}

TEST(OrderTests, CalculatePriceTest)
{
    std::shared_ptr<Management> management = std::make_shared<Management>();
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management.get());
    management->setKitchen(kitchen);
    Section* section = management->getGeneralSection().get();
    std::shared_ptr<Waiter> waiterPtr = std::make_shared<Waiter>(section, management.get());

    // Create instances of Food and Beverages directly
    std::unordered_map<std::string, int> foodIngredients = {{"flour", 2}, {"sugar", 1}};
    std::unordered_map<std::string, int> beverageIngredients = {{"water", 1}, {"vodka", 2},{"lemonade", 3}};

    std::shared_ptr<MenuItem> foodItem = std::make_shared<Food>(10.99, "Pancakes", foodIngredients);
    std::shared_ptr<MenuItem> beverageItem = std::make_shared<Beverage>(true,8.50, "Vodka Lemonade", beverageIngredients);

    std::vector<std::shared_ptr<MenuItem>> items = {foodItem, beverageItem};

    std::shared_ptr<Table> table = section->getTables()[0];

    std::shared_ptr<Order> order = std::make_shared<Order>(table,items, waiterPtr.get());

    // Check if the table number, waiter, and meals are set correctly
    EXPECT_EQ(order->calculatePrice(), 10.99 + 8.50);
}

TEST(OrderTest, CalculateIngredientsTest)
{
    std::shared_ptr<Management> management = std::make_shared<Management>();
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management.get());
    management->setKitchen(kitchen);
    Section* section = management->getGeneralSection().get();
    std::shared_ptr<Waiter> waiterPtr = std::make_shared<Waiter>(section, management.get());

    // Create instances of Food and Beverages directly
    std::unordered_map<std::string, int> foodIngredients = {{"flour", 2}, {"sugar", 1}};
    std::unordered_map<std::string, int> beverageIngredients = {{"water", 1}, {"vodka", 2},{"lemonade", 3}};

    std::shared_ptr<MenuItem> foodItem = std::make_shared<Food>(10.99, "Pancakes", foodIngredients);
    std::shared_ptr<MenuItem> beverageItem = std::make_shared<Beverage>(true,8.50, "Vodka Lemonade", beverageIngredients);

    std::vector<std::shared_ptr<MenuItem>> items = {foodItem, beverageItem};

    std::shared_ptr<Table> table = section->getTables()[0];

    std::shared_ptr<Order> order = std::make_shared<Order>(table,items, waiterPtr.get());

    // Check if the table number, waiter, and meals are set correctly
    EXPECT_EQ(order->calculateIngredients().size(), 5);
    EXPECT_EQ(order->calculateIngredients()["flour"], 2);
    EXPECT_EQ(order->calculateIngredients()["sugar"], 1);
    EXPECT_EQ(order->calculateIngredients()["water"], 1);
    EXPECT_EQ(order->calculateIngredients()["vodka"], 2);
    EXPECT_EQ(order->calculateIngredients()["lemonade"], 3);

}

TEST(OrderTest, AddMealTest)
{
    std::shared_ptr<Management> management = std::make_shared<Management>();
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management.get());
    management->setKitchen(kitchen);
    Section* section = management->getGeneralSection().get();
    std::shared_ptr<Waiter> waiterPtr = std::make_shared<Waiter>(section, management.get());

    // Create instances of Food and Beverages directly
    std::unordered_map<std::string, int> foodIngredients = {{"flour", 2}, {"sugar", 1}};
    std::unordered_map<std::string, int> beverageIngredients = {{"water", 1}, {"vodka", 2},{"lemonade", 3}};

    std::shared_ptr<MenuItem> foodItem = std::make_shared<Food>(10.99, "Pancakes", foodIngredients);
    std::shared_ptr<MenuItem> beverageItem = std::make_shared<Beverage>(true,8.50, "Vodka Lemonade", beverageIngredients);

    std::vector<std::shared_ptr<MenuItem>> items = {foodItem, beverageItem};

    std::shared_ptr<Table> table = section->getTables()[0];

    std::shared_ptr<Order> order = std::make_shared<Order>(table,items, waiterPtr.get());

    EXPECT_EQ(order->getMeals().size(), 2);

    std::shared_ptr<MenuItem> beverageItem2 = std::make_shared<Beverage>(false, 8.50, "Waffles", beverageIngredients);

    // Add the second meal to the order
    order->addMeal(beverageItem2);

    EXPECT_EQ(order->getMeals().size(), 3);

    // Check if the order now contains both meals
    EXPECT_EQ(order->getMeals()[0]->getName(), "Pancakes");
    EXPECT_EQ(order->getMeals()[1]->getName(), "Vodka Lemonade");
    EXPECT_EQ(order->getMeals()[2]->getName(), "Waffles");
}



