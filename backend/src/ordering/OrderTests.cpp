// #include "gtest/gtest.h"

// // include the necessary files
// #include "Order.h"
// #include "Meal.h"
// #include "Waiter.h"
// #include "Food.h"
// #include "Beverage.h"

// //extra includes
// #include "AbstractOrder.cpp"
// #include "MenuItem.cpp"
// #include "Order.cpp"
// #include "Meal.cpp"
// #include "Waiter.cpp"
// #include "Food.cpp"
// #include "Beverage.cpp"

// TEST(OrderTests, calculateIngredientsTest) {
//     // Create some meals with ingredients
//     std::unordered_map<std::string, int> ingredients1;
//     ingredients1["spaghetti"] = 200;
//     ingredients1["bacon"] = 100;
//     ingredients1["eggs"] = 2;
//     ingredients1["parmesan cheese"] = 50;
//     std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(100.0, "Spaghetti Carbonara", "Josh", ingredients1);

//     std::unordered_map<std::string, int> ingredients2;
//     ingredients2["pizza dough"] = 300;
//     ingredients2["tomato sauce"] = 100;
//     ingredients2["mozzarella cheese"] = 150;
//     std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(140.60,"Margherita Pizza","Ashely",ingredients2);

//     std::unordered_map<std::string, int> ingredients3;
//     ingredients3["lettuce"] = 100;
//     ingredients3["chicken breast"] = 200;
//     ingredients3["croutons"] = 50;
//     ingredients3["parmesan cheese"] = 50;
//     std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(120.0,"Caesar Salad","Ayanda",ingredients3);

//     std::unordered_map<std::string, int> ingredients4;
//     ingredients4["lemon"] = 100;
//     ingredients4["water"] = 200;
//     ingredients4["sugar"] = 50;
//     ingredients4["ice"] = 50;
//     std::shared_ptr<Meal> meal4 = std::make_shared<Meal>(120.0,"Lemonade","Chenoa",ingredients4);

//     // creating the shared pointer for the meals
//     std::shared_ptr<Food> meal1Ptr = std::make_shared<Food>(meal1->getPrice(), meal1->getName(), meal1->getIngredients());
//     std::shared_ptr<Food> meal2Ptr = std::make_shared<Food>(meal2->getPrice(), meal2->getName(), meal2->getIngredients());
//     std::shared_ptr<Food> meal3Ptr = std::make_shared<Food>(meal3->getPrice(), meal3->getName(), meal3->getIngredients());
//     std::shared_ptr<Beverage> meal4Ptr = std::make_shared<Beverage>(false,meal4->getPrice(), meal4->getName(), meal4->getIngredients());
    
//     //creating the vector for the meals
//     std::vector<std::shared_ptr<MenuItem>> meals;

//     meals.push_back(meal1Ptr);
//     meals.push_back(meal2Ptr);
//     meals.push_back(meal3Ptr);
//     meals.push_back(meal4Ptr);

//     // create the waiter
//     std::shared_ptr<Waiter> waiter = std::make_shared<Waiter>("Thato", 1);

//     // Create an order with the meals
//     Order order(1, meals, waiter);

//     // Calculate the ingredients
//     std::unordered_map<std::string, int> ingredients = order.calculateIngredients();

//     // Check the ingredients
//     EXPECT_EQ(ingredients["spaghetti"], 200);
//     EXPECT_EQ(ingredients["bacon"], 100);
//     EXPECT_EQ(ingredients["eggs"], 2);
//     EXPECT_EQ(ingredients["parmesan cheese"], 100);
//     EXPECT_EQ(ingredients["pizza dough"], 300);
//     EXPECT_EQ(ingredients["tomato sauce"], 100);
//     EXPECT_EQ(ingredients["mozzarella cheese"], 150);
//     EXPECT_EQ(ingredients["lettuce"], 100);
//     EXPECT_EQ(ingredients["chicken breast"], 200);
//     EXPECT_EQ(ingredients["croutons"], 50);
//     EXPECT_EQ(ingredients["lemon"], 100);
//     EXPECT_EQ(ingredients["water"], 200);
//     EXPECT_EQ(ingredients["sugar"], 50);
//     EXPECT_EQ(ingredients["ice"], 50);
// }

// TEST(OrderTests, calculatePriceTest) {
//     // Create some meals with ingredients
//     std::unordered_map<std::string, int> ingredients1;
//     ingredients1["spaghetti"] = 200;
//     ingredients1["bacon"] = 100;
//     ingredients1["eggs"] = 2;
//     ingredients1["parmesan cheese"] = 50;
//     std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(100.0, "Spaghetti Carbonara", "Josh", ingredients1);

//     std::unordered_map<std::string, int> ingredients2;
//     ingredients2["pizza dough"] = 300;
//     ingredients2["tomato sauce"] = 100;
//     ingredients2["mozzarella cheese"] = 150;
//     std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(140.60,"Margherita Pizza","Ashely",ingredients2);

//     std::unordered_map<std::string, int> ingredients3;
//     ingredients3["lettuce"] = 100;
//     ingredients3["chicken breast"] = 200;
//     ingredients3["croutons"] = 50;
//     ingredients3["parmesan cheese"] = 50;
//     std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(120.0,"Caesar Salad","Ayanda",ingredients3);

//     std::unordered_map<std::string, int> ingredients4;
//     ingredients4["lemon"] = 100;
//     ingredients4["water"] = 200;
//     ingredients4["sugar"] = 50;
//     ingredients4["ice"] = 50;
//     std::shared_ptr<Meal> meal4 = std::make_shared<Meal>(120.0,"Lemonade","Chenoa",ingredients4);

//     // creating the shared pointer for the meals
//     std::shared_ptr<Food> meal1Ptr = std::make_shared<Food>(meal1->getPrice(), meal1->getName(), meal1->getIngredients());
//     std::shared_ptr<Food> meal2Ptr = std::make_shared<Food>(meal2->getPrice(), meal2->getName(), meal2->getIngredients());
//     std::shared_ptr<Food> meal3Ptr = std::make_shared<Food>(meal3->getPrice(), meal3->getName(), meal3->getIngredients());
//     std::shared_ptr<Beverage> meal4Ptr = std::make_shared<Beverage>(false,meal4->getPrice(), meal4->getName(), meal4->getIngredients());
    
//     //creating the vector for the meals
//     std::vector<std::shared_ptr<MenuItem>> meals;

//     meals.push_back(meal1Ptr);
//     meals.push_back(meal2Ptr);
//     meals.push_back(meal3Ptr);
//     meals.push_back(meal4Ptr);

//     double expectedPrice = 0;

//     for (auto meal : meals) {
//         expectedPrice += meal->getMealPrice();
//     }

//     // create the waiter
//     std::shared_ptr<Waiter> waiter = std::make_shared<Waiter>("Thato", 1);

//     // Create an order with the meals
//     Order order(1, meals, waiter);

//     // Check the price
//     EXPECT_EQ(order.calculatePrice(), expectedPrice);
// }

// TEST(OrderTests, AddOrderTest){
//     // Create some meals with ingredients
//     std::unordered_map<std::string, int> ingredients1;
//     ingredients1["spaghetti"] = 200;
//     ingredients1["bacon"] = 100;
//     ingredients1["eggs"] = 2;
//     ingredients1["parmesan cheese"] = 50;
//     ingredients1["tomato sauce"] = 50;
//     std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(100.0, "Spaghetti Carbonara", "Josh", ingredients1);

//     std::unordered_map<std::string, int> ingredients2;
//     ingredients2["pizza dough"] = 300;
//     ingredients2["tomato sauce"] = 100;
//     ingredients2["mozzarella cheese"] = 150;
//     std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(140.60,"Margherita Pizza","Ashely",ingredients2);

//     // creating the shared pointer for the meals
//     std::shared_ptr<Food> meal1Ptr = std::make_shared<Food>(meal1->getPrice(), meal1->getName(), meal1->getIngredients());
//     std::shared_ptr<Food> meal2Ptr = std::make_shared<Food>(meal2->getPrice(), meal2->getName(), meal2->getIngredients());

//     //creating the vector for the meals
//     std::vector<std::shared_ptr<MenuItem>> meals;

//     meals.push_back(meal1Ptr);
//     meals.push_back(meal2Ptr);

//     // create the waiter
//     std::shared_ptr<Waiter> waiter = std::make_shared<Waiter>("Thato", 1);

//     double expectedPrice = 0;

//     for (auto meal : meals) {
//         expectedPrice += meal->getMealPrice();
//     }

//     // Create an order with the meals
//     Order order(1, meals, waiter);

//     // Check the price
//     EXPECT_EQ(order.calculatePrice(), expectedPrice);

//     // Check the ingredients
//     std::unordered_map<std::string, int> ingredients = order.calculateIngredients();

//     EXPECT_EQ(ingredients["spaghetti"], 200);
//     EXPECT_EQ(ingredients["bacon"], 100);
//     EXPECT_EQ(ingredients["eggs"], 2);
//     EXPECT_EQ(ingredients["parmesan cheese"], 50);
//     EXPECT_EQ(ingredients["tomato sauce"], 150);
//     EXPECT_EQ(ingredients["pizza dough"], 300);
//     EXPECT_EQ(ingredients["mozzarella cheese"], 150);

//     // Create another meal with ingredients
//     std::unordered_map<std::string, int> ingredients3;
//     ingredients3["lettuce"] = 100;
//     ingredients3["chicken breast"] = 200;
//     ingredients3["croutons"] = 50;
//     ingredients3["parmesan cheese"] = 50;
//     std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(120.0,"Caesar Salad","Ayanda",ingredients3);

//     // creating the shared pointer for the meal
//     std::shared_ptr<Food> meal3Ptr = std::make_shared<Food>(meal3->getPrice(), meal3->getName(), meal3->getIngredients());

//     // Add the meal to the order
//     order.addMeal(meal3Ptr);

//     // Check the price
//     expectedPrice += meal3Ptr->getMealPrice();
//     EXPECT_EQ(order.calculatePrice(), expectedPrice);

//     // Check the ingredients
//     ingredients = order.calculateIngredients();

//     EXPECT_EQ(ingredients["spaghetti"], 200);
//     EXPECT_EQ(ingredients["bacon"], 100);
//     EXPECT_EQ(ingredients["eggs"], 2);
//     EXPECT_EQ(ingredients["parmesan cheese"], 100);
//     EXPECT_EQ(ingredients["tomato sauce"], 150);
//     EXPECT_EQ(ingredients["pizza dough"], 300);
//     EXPECT_EQ(ingredients["mozzarella cheese"], 150);
//     EXPECT_EQ(ingredients["lettuce"], 100);
//     EXPECT_EQ(ingredients["chicken breast"], 200);
//     EXPECT_EQ(ingredients["croutons"], 50);

// }

// TEST(OrderTests, RemoveOrderTest){
//     // Create some meals with ingredients
//     std::unordered_map<std::string, int> ingredients1;
//     ingredients1["spaghetti"] = 200;
//     ingredients1["bacon"] = 100;
//     ingredients1["eggs"] = 2;
//     ingredients1["parmesan cheese"] = 50;
//     ingredients1["tomato sauce"] = 50;
//     std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(100.0, "Spaghetti Carbonara", "Josh", ingredients1);

//     std::unordered_map<std::string, int> ingredients2;
//     ingredients2["pizza dough"] = 300;
//     ingredients2["tomato sauce"] = 100;
//     ingredients2["mozzarella cheese"] = 150;
//     std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(140.60,"Margherita Pizza","Ashely",ingredients2);

//     std::unordered_map<std::string, int> ingredients3;
//     ingredients3["lettuce"] = 100;
//     ingredients3["chicken breast"] = 200;
//     ingredients3["croutons"] = 50;
//     ingredients3["parmesan cheese"] = 50;
//     std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(120.0,"Caesar Salad","Ayanda",ingredients3);

//     // creating the shared pointer for the meals
//     std::shared_ptr<Food> meal1Ptr = std::make_shared<Food>(meal1->getPrice(), meal1->getName(), meal1->getIngredients());
//     std::shared_ptr<Food> meal2Ptr = std::make_shared<Food>(meal2->getPrice(), meal2->getName(), meal2->getIngredients());
//     std::shared_ptr<Food> meal3Ptr = std::make_shared<Food>(meal3->getPrice(), meal3->getName(), meal3->getIngredients());

//     //creating the vector for the meals
//     std::vector<std::shared_ptr<MenuItem>> meals;

//     meals.push_back(meal1Ptr);
//     meals.push_back(meal2Ptr);
//     meals.push_back(meal3Ptr);

//     // create the waiter
//     std::shared_ptr<Waiter> waiter = std::make_shared<Waiter>("Thato", 1);

//     double expectedPrice = 0;

//     for (auto meal : meals) {
//         expectedPrice += meal->getMealPrice();
//     }

//     // Create an order with the meals
//     Order order(1, meals, waiter);

//     // Check the price
//     EXPECT_EQ(order.calculatePrice(), expectedPrice);

//     // Check the ingredients
//     std::unordered_map<std::string, int> ingredients = order.calculateIngredients();

//     EXPECT_EQ(ingredients["spaghetti"], 200);
//     EXPECT_EQ(ingredients["bacon"], 100);
//     EXPECT_EQ(ingredients["eggs"], 2);
//     EXPECT_EQ(ingredients["parmesan cheese"], 100);
//     EXPECT_EQ(ingredients["tomato sauce"], 150);
//     EXPECT_EQ(ingredients["pizza dough"], 300);
//     EXPECT_EQ(ingredients["mozzarella cheese"], 150);
//     EXPECT_EQ(ingredients["lettuce"], 100);
//     EXPECT_EQ(ingredients["chicken breast"], 200);
//     EXPECT_EQ(ingredients["croutons"], 50);

//     //remove a meal
//     order.removeMeal(meal3Ptr);
    
//     // Check the price
//     EXPECT_EQ(order.calculatePrice(), 240.6);

//     // Check the ingredients
//     ingredients = order.calculateIngredients();

//     EXPECT_EQ(ingredients["spaghetti"], 200);
//     EXPECT_EQ(ingredients["bacon"], 100);
//     EXPECT_EQ(ingredients["eggs"], 2);
//     EXPECT_EQ(ingredients["parmesan cheese"], 50);
//     EXPECT_EQ(ingredients["tomato sauce"], 150);
//     EXPECT_EQ(ingredients["pizza dough"], 300);
//     EXPECT_EQ(ingredients["mozzarella cheese"], 150);
    
// }

// TEST(OrderTests, GetMealTest){
//     // Create some meals with ingredients
//     std::unordered_map<std::string, int> ingredients1;
//     ingredients1["spaghetti"] = 200;
//     ingredients1["bacon"] = 100;
//     ingredients1["eggs"] = 2;
//     ingredients1["parmesan cheese"] = 50;
//     std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(100.0, "Spaghetti Carbonara", "Josh", ingredients1);

//     std::unordered_map<std::string, int> ingredients2;
//     ingredients2["pizza dough"] = 300;
//     ingredients2["tomato sauce"] = 100;
//     ingredients2["mozzarella cheese"] = 150;
//     std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(140.60,"Margherita Pizza","Ashely",ingredients2);

//     std::unordered_map<std::string, int> ingredients3;
//     ingredients3["lettuce"] = 100;
//     ingredients3["chicken breast"] = 200;
//     ingredients3["croutons"] = 50;
//     ingredients3["parmesan cheese"] = 50;
//     std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(120.0,"Caesar Salad","Ayanda",ingredients3);

//     std::unordered_map<std::string, int> ingredients4;
//     ingredients4["lemon"] = 100;
//     ingredients4["water"] = 200;
//     ingredients4["sugar"] = 50;
//     ingredients4["ice"] = 50;
//     std::shared_ptr<Meal> meal4 = std::make_shared<Meal>(120.0,"Lemonade","Chenoa",ingredients4);

//     // creating the shared pointer for the meals
//     std::shared_ptr<Food> meal1Ptr = std::make_shared<Food>(meal1->getPrice(), meal1->getName(), meal1->getIngredients());
//     std::shared_ptr<Food> meal2Ptr = std::make_shared<Food>(meal2->getPrice(), meal2->getName(), meal2->getIngredients());
//     std::shared_ptr<Food> meal3Ptr = std::make_shared<Food>(meal3->getPrice(), meal3->getName(), meal3->getIngredients());
//     std::shared_ptr<Beverage> meal4Ptr = std::make_shared<Beverage>(false,meal4->getPrice(), meal4->getName(), meal4->getIngredients());
    
//     //creating the vector for the meals
//     std::vector<std::shared_ptr<MenuItem>> meals;

//     meals.push_back(meal1Ptr);
//     meals.push_back(meal2Ptr);
//     meals.push_back(meal3Ptr);
//     meals.push_back(meal4Ptr);

//     // create the waiter
//     std::shared_ptr<Waiter> waiter = std::make_shared<Waiter>("Thato", 1);

//     // Create an order with the meals
//     Order order(1, meals, waiter);

//     // Get a meal
//     std::shared_ptr<MenuItem> meal = order.getMeal("Spaghetti Carbonara");

//     // Check the meal
//     EXPECT_EQ(meal->getName(), "Spaghetti Carbonara");

//     // Get a meal thats not in the order
//     std::shared_ptr<MenuItem> NotThereMeal = order.getMeal("Pasta");

//     // Check the meal
//     EXPECT_EQ(NotThereMeal, nullptr);
// }
