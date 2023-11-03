// #include <gtest/gtest.h>
// #include <memory>
// #include "../includes/include_all.h" 

// TEST(OrderTest, ConstructorTest)
// {
//     Waiter waiter; // Create a Waiter object using the default constructor
//     std::shared_ptr<Waiter> waiterPtr = std::make_shared<Waiter>(waiter);

//     // Create instances of Food and Beverages directly
//     std::unordered_map<std::string, int> foodIngredients = {{"flour", 2}, {"sugar", 1}};
//     std::unordered_map<std::string, int> beverageIngredients = {{"water", 1}, {"sugar", 2}};

//     std::shared_ptr<MenuItem> foodItem = std::make_shared<Food>(10.99, "Pancakes", foodIngredients);
//     std::shared_ptr<MenuItem> beverageItem = std::make_shared<Beverage>(true,8.50, "Waffles", beverageIngredients);

//     std::vector<std::shared_ptr<MenuItem>> items = {foodItem, beverageItem};

//     Order order(2, items, waiterPtr);

//     // Check if the table number, waiter, and meals are set correctly
//     EXPECT_EQ(order.getTableNumber(), 2);
//     EXPECT_EQ(order.getWaiter(), waiterPtr);
//     EXPECT_EQ(order.getMeals().size(), items.size());
// }


// TEST(OrderTest, CalculatePriceTest)
// {
//     // Create instances of Food and Beverages directly
//     std::unordered_map<std::string, int> foodIngredients = {{"flour", 2}, {"sugar", 1}};
//     std::unordered_map<std::string, int> beverageIngredients = {{"water", 1}, {"sugar", 2}};

//     std::shared_ptr<MenuItem> foodItem = std::make_shared<Food>(10.99, "Pancakes", foodIngredients);
//     std::shared_ptr<MenuItem> beverageItem = std::make_shared<Beverage>(true,8.50, "Waffles", beverageIngredients);

//     std::vector<std::shared_ptr<MenuItem>> items = {foodItem, beverageItem};

//     Order order(2, items, std::make_shared<Waiter>());

//     // Check if the calculated price matches the expected sum of meal prices
//     EXPECT_DOUBLE_EQ(order.calculatePrice(), 10.99 + 8.50);
// }


// TEST(OrderTest, CalculateIngredientsTest)
// {
//     // Create instances of Food and Beverages
//     std::unordered_map<std::string, int> foodIngredients = {{"flour", 2}, {"sugar", 1}};
//     std::unordered_map<std::string, int> beverageIngredients = {{"flour", 2}, {"sugar", 1}};

//     std::shared_ptr<MenuItem> foodItem = std::make_shared<Food>(10.99, "Pancakes", foodIngredients);
//     std::shared_ptr<MenuItem> beverageItem = std::make_shared<Beverage>(true,8.50, "Waffles", beverageIngredients);

//     // Create an Order with the above items
//     std::vector<std::shared_ptr<MenuItem>> items = {foodItem, beverageItem};
//     Order order(2, items, std::make_shared<Waiter>());

//     // Calculate ingredients and check if they match the expected result
//     std::unordered_map<std::string, int> expectedIngredients = {{"flour", 4}, {"sugar", 2}};
//     EXPECT_EQ(order.calculateIngredients(), expectedIngredients);
// }

// TEST(OrderTest, AddMealTest)
// {
//     // Create instances of Food and Beverages directly
//     std::unordered_map<std::string, int> foodIngredients = {{"flour", 2}, {"sugar", 1}};
//     std::unordered_map<std::string, int> beverageIngredients = {{"water", 1}, {"sugar", 2}};

//     std::shared_ptr<MenuItem> foodItem1 = std::make_shared<Food>(10.99, "Pancakes", foodIngredients);
//     std::shared_ptr<MenuItem> beverageItem2 = std::make_shared<Beverage>(false, 8.50, "Waffles", beverageIngredients);

//     // Create an Order with the first meal
//     std::vector<std::shared_ptr<MenuItem>> meals = {foodItem1};
//     Order order(2, meals, std::make_shared<Waiter>());

//     // Add the second meal to the order
//     order.addMeal(beverageItem2);

//     // Check if the order now contains both meals
//     EXPECT_EQ(order.getMeals().size(), 2);
//     EXPECT_EQ(order.getMeals()[0]->getName(), "Pancakes");
//     EXPECT_EQ(order.getMeals()[1]->getName(), "Waffles");
// }

// TEST(OrderTest, RemoveMealTest) {
//     // Create instances of Food and Beverages directly
//     std::unordered_map<std::string, int> foodIngredients1 = {{"flour", 2}, {"sugar", 1}};
//     std::unordered_map<std::string, int> beverageIngredients2 = {{"water", 1}, {"sugar", 2}};

//     std::shared_ptr<MenuItem> foodItem1 = std::make_shared<Food>(10.99, "Pancakes", foodIngredients1);
//     std::shared_ptr<MenuItem> beverageItem2 = std::make_shared<Beverage>(false, 8.50, "Waffles", beverageIngredients2);

//     // Create an Order with both meals
//     std::vector<std::shared_ptr<MenuItem>> meals = {foodItem1, beverageItem2};
//     Order order(2, meals, std::make_shared<Waiter>());

//     // Remove the first meal from the order
//     bool removed = order.removeMeal(foodItem1);

//     // Check if the meal was successfully removed and the order now contains only one meal
//     EXPECT_TRUE(removed);
//     EXPECT_EQ(order.getMeals().size(), 1);
//     EXPECT_EQ(order.getMeals()[0]->getName(), "Waffles");

//     // Try to remove a non-existent meal and ensure it returns false
//     std::unordered_map<std::string, int> noIngredients = {{}};
//     std::shared_ptr<MenuItem> nonExistentMeal = std::make_shared<Food>(5.0, "Burger", noIngredients);
//     removed = order.removeMeal(nonExistentMeal);
//     EXPECT_FALSE(removed);
// }
