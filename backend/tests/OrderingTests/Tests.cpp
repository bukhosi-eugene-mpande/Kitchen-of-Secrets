#include <gtest/gtest.h>
#include <memory>

#include "../includes/include_all.h"
#include "../includes/include_all.cpp"

TEST(BeverageTest, ConstructorTest) {
    std::unordered_map<std::string, int> ingredients = {{"water", 1}, {"sugar", 2}};
    Beverage beverage(false, 2.5, "Lemonade", ingredients);
    EXPECT_EQ(beverage.calculatePrice(), 2.5);
    EXPECT_EQ(beverage.getName(), "Lemonade");
    EXPECT_EQ(beverage.calculateIngredients(), ingredients);
    EXPECT_FALSE(beverage.getIsAlcoholic());
}

TEST(BeverageTest, AlcoholicTest) {
    std::unordered_map<std::string, int> ingredients = {{"water", 1}, {"sugar", 2},{"vodka", 1}};
    Beverage beverage(true, 4.5, "Spiked Lemonade", ingredients);
    EXPECT_EQ(beverage.calculatePrice(), 4.5);
    EXPECT_EQ(beverage.getName(), "Spiked Lemonade");
    EXPECT_EQ(beverage.calculateIngredients(), ingredients);
    EXPECT_TRUE(beverage.getIsAlcoholic());
    
}

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

TEST(MenuTest, MenuConstructorTest){
    //shared_ptr<Management> management
    std::shared_ptr<PlayerInteraction> management = std::make_shared<PlayerInteraction>();

    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management.get());

    std::shared_ptr<Menu> Bevmenu = std::make_shared<Menu>(kitchen->getDrinksMenu());

    std::shared_ptr<Menu> Foodmenu = std::make_shared<Menu>(kitchen->getCuisineMenu());

    EXPECT_EQ(Bevmenu->getMenuItems().size(), 10);
    EXPECT_EQ(Foodmenu->getMenuItems().size(), 15);

}

TEST(OrderTests, OrderConstructorTest){
    std::shared_ptr<PlayerInteraction> management = std::make_shared<PlayerInteraction>();
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
    std::shared_ptr<PlayerInteraction> management = std::make_shared<PlayerInteraction>();
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
    std::shared_ptr<PlayerInteraction> management = std::make_shared<PlayerInteraction>();
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
    std::shared_ptr<PlayerInteraction> management = std::make_shared<PlayerInteraction>();
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

TEST(OrderBuilderTest, CreateOrderTest) 
{
    std::shared_ptr<PlayerInteraction> management = std::make_shared<PlayerInteraction>();
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management.get());
    management->setKitchen(kitchen);
    Section* section = management->getGeneralSection().get();
    std::shared_ptr<Waiter> waiterPtr = std::make_shared<Waiter>(section, management.get());

    // Create an instance of OrderBuilder
    std::shared_ptr<OrderBuilder> orderBuilder = std::make_shared<OrderBuilder>();

    // Set the table
    std::shared_ptr<Table> table = section->getTables()[0];
    orderBuilder->setTable(table);

    // Set the waiter
    orderBuilder->setWaiter(waiterPtr.get());

    // Create instances of Food or Beverage as needed
    std::unordered_map<std::string, int> ingredients1 = {{"flour", 2}, {"sugar", 1}};
    std::shared_ptr<MenuItem> meal1 = std::make_shared<Food>(8.50, "Pancakes", ingredients1);

    std::unordered_map<std::string, int> ingredients2 = {{"water", 1}, {"sugar", 2}};
    std::shared_ptr<MenuItem> meal2 = std::make_shared<Beverage>(true, 2.99, "Cola", ingredients2);

    // Add meals to the order
    orderBuilder->addMeal(meal1);
    orderBuilder->addMeal(meal2);

    // Get the final order
    std::shared_ptr<Order> order = orderBuilder->getOrder();

    // Verify that the created order matches the expected values
    EXPECT_EQ(order->getTable(), table);
    EXPECT_EQ(order->getWaiter(), waiterPtr.get());
    EXPECT_EQ(order->getMeals().size(), 2); // Assuming two meals were added

    // Reset the OrderBuilder for creating a new order
    orderBuilder->reset();

}


