#include <gtest/gtest.h>
#include <memory>
#include "./includes/include_all.h" 

TEST(OrderTest, ConstructorTest) {
    Waiter waiter; // Create a Waiter object using the default constructor
    std::shared_ptr<Waiter> waiterPtr = std::make_shared<Waiter>(waiter);

    
    // Create instances of ConcreteMenuItem
    std::unordered_map<std::string, int> ingredients1 = {{"flour", 2}, {"sugar", 1}};
    std::unordered_map<std::string, int> ingredients2 = {{"flour", 2}, {"sugar", 1}};
    
    std::shared_ptr<MenuItem> meal1 = std::make_shared<ConcreteMenuItem>(10.99, "Pancakes", ingredients1);
    std::shared_ptr<MenuItem> meal2 = std::make_shared<ConcreteMenuItem>(8.50, "Waffles", ingredients2);
    
    std::vector<std::shared_ptr<MenuItem>> meals = {meal1, meal2};
    
    Order order(2, meals, waiterPtr);
    
    // Check if the table number, waiter, and meals are set correctly
    
    EXPECT_EQ(order.getTableNumber(), 2);
    EXPECT_EQ(order.getWaiter(), waiterPtr);
    EXPECT_EQ(order.getMeals().size(), meals.size());
}