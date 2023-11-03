
#include <gtest/gtest.h>
#include <memory>
#include "../includes/include_all.h" 

TEST(OrderBuilderTest, CreateOrderTest) 
{
    // Create an instance of OrderBuilder
    OrderBuilder orderBuilder;

    // Set the table number
    int tableNumber = 2;
    orderBuilder.setTableNumber(tableNumber);

    // Set the waiter
    Waiter waiter; // Create a Waiter object using the default constructor
    std::shared_ptr<Waiter> waiterPtr = std::make_shared<Waiter>(waiter);
    orderBuilder.setWaiter(waiterPtr);

    // Create instances of Food or Beverage as needed
    std::unordered_map<std::string, int> ingredients1 = {{"flour", 2}, {"sugar", 1}};
    std::shared_ptr<MenuItem> meal1 = std::make_shared<Food>(8.50, "Pancakes", ingredients1);

    std::unordered_map<std::string, int> ingredients2 = {{"water", 1}, {"sugar", 2}};
    std::shared_ptr<MenuItem> meal2 = std::make_shared<Beverage>(true, 2.99, "Cola", ingredients2);

    // Add meals to the order
    orderBuilder.addMeal(meal1);
    orderBuilder.addMeal(meal2);
        // Get the final order
    std::shared_ptr<Order> order = orderBuilder.getOrder();

    // Verify that the created order matches the expected values
    EXPECT_EQ(order->getTableNumber(), tableNumber);
    EXPECT_EQ(order->getWaiter(), waiterPtr);
    EXPECT_EQ(order->getMeals().size(), 2); // Assuming two meals were added
    // You can add more assertions to check other properties of the order

    // Reset the OrderBuilder for creating a new order
    orderBuilder.reset();
}