#include <gtest/gtest.h>
#include <memory>

#include "include_all.cpp"

TEST(KitchenTest,ConstructorTest){  
    std::unordered_map<std::string, int> ingredients1 = {{"basil", 1}, {"pine nuts", 2}, {"garlic", 3}};
    std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(12.99, "Pesto Pasta", "Cook", ingredients1);

    std::unordered_map<std::string, int> ingredients2 = {{"salt", 2}, {"pepper", 1}, {"garlic", 3}};
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(10.99, "Spaghetti Carbonara", "Baker", ingredients2);

    std::unordered_map<std::string, int> ingredients3 = {{"lemon", 2}, {"pepper", 1}, {"wings", 3}};
    std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(10.99, "Lemon pepper wings", "Grill chef", ingredients3);
    
    //vector of meals
    std::vector <std::shared_ptr<Meal>> meals = {meal1, meal2, meal3};

    //shared_ptr<Management> management
    Management* management = new Management();
    
    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management, meals);
    
    //check magament
    EXPECT_EQ(kitchen->getManagement(), management);

}

TEST(KitchenTest, AddMealTest){  
    std::unordered_map<std::string, int> ingredients1 = {{"basil", 1}, {"pine nuts", 2}, {"garlic", 3}};
    std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(12.99, "Pesto Pasta", "Cook", ingredients1);

    std::unordered_map<std::string, int> ingredients2 = {{"salt", 2}, {"pepper", 1}, {"garlic", 3}};
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(10.99, "Spaghetti Carbonara", "Baker", ingredients2);

    std::unordered_map<std::string, int> ingredients3 = {{"lemon", 2}, {"pepper", 1}, {"wings", 3}};
    std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(10.99, "Lemon pepper wings", "Grill chef", ingredients3);
    
    //vector of meals
    std::vector <std::shared_ptr<Meal>> meals = {meal1, meal2};

    //shared_ptr<Management> management
    Management* management = new Management();
    
    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management, meals);
    
    //check magament
    EXPECT_EQ(kitchen->getManagement(), management);

    //check meals
    EXPECT_EQ(kitchen->getAvailableMeals().size(), 2);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Pesto Pasta"), 1);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Spaghetti Carbonara"), 1);

    //add a new meal
    kitchen->addMeal(meal3);

    //check meals again
    EXPECT_EQ(kitchen->getAvailableMeals().size(), 3);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Pesto Pasta"), 1);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Spaghetti Carbonara"), 1);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Lemon pepper wings"), 1);
}

TEST(KitchenTest, RemoveMealTest){  
    std::unordered_map<std::string, int> ingredients1 = {{"basil", 1}, {"pine nuts", 2}, {"garlic", 3}};
    std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(12.99, "Pesto Pasta", "Cook", ingredients1);

    std::unordered_map<std::string, int> ingredients2 = {{"salt", 2}, {"pepper", 1}, {"garlic", 3}};
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(10.99, "Spaghetti Carbonara", "Baker", ingredients2);

    std::unordered_map<std::string, int> ingredients3 = {{"lemon", 2}, {"pepper", 1}, {"wings", 3}};
    std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(10.99, "Lemon pepper wings", "Grill chef", ingredients3);
    
    //vector of meals
    std::vector <std::shared_ptr<Meal>> meals = {meal1, meal2, meal3};

    //shared_ptr<Management> management
    Management* management = new Management();
    
    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management, meals);
    
    //check meals
    EXPECT_EQ(kitchen->getAvailableMeals().size(), 3);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Pesto Pasta"), 1);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Spaghetti Carbonara"), 1);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Lemon pepper wings"), 1);

    //remove a meal
    kitchen->removeMeal("Pesto Pasta");

    //check meals again
    EXPECT_EQ(kitchen->getAvailableMeals().size(), 2);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Pesto Pasta"), 0);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Spaghetti Carbonara"), 1);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Lemon pepper wings"), 1);

    //try to remove a non-existing meal
    kitchen->removeMeal("Non-existing meal");

    //check meals again
    EXPECT_EQ(kitchen->getAvailableMeals().size(), 2);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Pesto Pasta"), 0);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Spaghetti Carbonara"), 1);
    EXPECT_EQ(kitchen->getAvailableMeals().count("Lemon pepper wings"), 1);
}

TEST(KitchenTest, GetMenuTest){  
    std::unordered_map<std::string, int> ingredients1 = {{"basil", 1}, {"pine nuts", 2}, {"garlic", 3}};
    std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(12.99, "Pesto Pasta", "Cook", ingredients1);

    std::unordered_map<std::string, int> ingredients2 = {{"salt", 2}, {"pepper", 1}, {"garlic", 3}};
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(10.99, "Spaghetti Carbonara", "Baker", ingredients2);

    std::unordered_map<std::string, int> ingredients3 = {{"lemon", 2}, {"pepper", 1}, {"wings", 3}};
    std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(10.99, "Lemon pepper wings", "Grill chef", ingredients3);
    
    //vector of meals
    std::vector <std::shared_ptr<Meal>> meals = {meal1, meal2, meal3};

    //shared_ptr<Management> management
    Management* management = new Management();
    
    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management, meals);

    //check menu
    std::unordered_map<int, std::string> expected_menu = {{1, "Lemon pepper wings"}, {2, "Spaghetti Carbonara"}, {3, "Pesto Pasta"}};
    EXPECT_EQ(kitchen->getMenu(), expected_menu);
}

TEST(KitchenTest, GetPriceTest){  
    std::unordered_map<std::string, int> ingredients1 = {{"basil", 1}, {"pine nuts", 2}, {"garlic", 3}};
    std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(12.99, "Pesto Pasta", "Cook", ingredients1);

    std::unordered_map<std::string, int> ingredients2 = {{"salt", 2}, {"pepper", 1}, {"garlic", 3}};
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(10.99, "Spaghetti Carbonara", "Baker", ingredients2);

    std::unordered_map<std::string, int> ingredients3 = {{"lemon", 2}, {"pepper", 1}, {"wings", 3}};
    std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(10.99, "Lemon pepper wings", "Grill chef", ingredients3);
    
    //vector of meals
    std::vector <std::shared_ptr<Meal>> meals = {meal1, meal2, meal3};

    //shared_ptr<Management> management
    Management* management = new Management();
    
    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management, meals);
    
    //check price of a meal
    EXPECT_EQ(kitchen->getPrice("Pesto Pasta"), 12.99);
    EXPECT_EQ(kitchen->getPrice("Spaghetti Carbonara"), 10.99);
    EXPECT_EQ(kitchen->getPrice("Lemon pepper wings"), 10.99);

}

TEST(KitchenTest, GetIngredientsTest){  
    std::unordered_map<std::string, int> ingredients1 = {{"basil", 1}, {"pine nuts", 2}, {"garlic", 3}};
    std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(12.99, "Pesto Pasta", "Cook", ingredients1);

    std::unordered_map<std::string, int> ingredients2 = {{"salt", 2}, {"pepper", 1}, {"garlic", 3}};
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(10.99, "Spaghetti Carbonara", "Baker", ingredients2);

    std::unordered_map<std::string, int> ingredients3 = {{"lemon", 2}, {"pepper", 1}, {"wings", 3}};
    std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(10.99, "Lemon pepper wings", "Grill chef", ingredients3);
    
    //vector of meals
    std::vector <std::shared_ptr<Meal>> meals = {meal1, meal2, meal3};

    //shared_ptr<Management> management
    Management* management = new Management();
    
    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management, meals);
    
    //check ingredients
    EXPECT_EQ(kitchen->getIngredients("Pesto Pasta"), ingredients1);
    EXPECT_EQ(kitchen->getIngredients("Spaghetti Carbonara"), ingredients2);
    EXPECT_EQ(kitchen->getIngredients("Lemon pepper wings"), ingredients3);
}

TEST(KitchenTest, CreateDeputyHeadChefTest){  
    std::unordered_map<std::string, int> ingredients1 = {{"basil", 1}, {"pine nuts", 2}, {"garlic", 3}};
    std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(12.99, "Pesto Pasta", "Cook", ingredients1);

    std::unordered_map<std::string, int> ingredients2 = {{"salt", 2}, {"pepper", 1}, {"garlic", 3}};
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(10.99, "Spaghetti Carbonara", "Baker", ingredients2);

    std::unordered_map<std::string, int> ingredients3 = {{"lemon", 2}, {"pepper", 1}, {"wings", 3}};
    std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(10.99, "Lemon pepper wings", "Grill chef", ingredients3);
    
    //vector of meals
    std::vector <std::shared_ptr<Meal>> meals = {meal1, meal2, meal3};

    //shared_ptr<Management> management
    Management* management = new Management();
    
    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management, meals);
    
    //check ingredients
    kitchen->createDeputyHeadChef();
    EXPECT_NE(kitchen->getDeputyHeadChef(), nullptr);
}

TEST(KitchenTest, CreateHeadChefTest){  
    std::unordered_map<std::string, int> ingredients1 = {{"basil", 1}, {"pine nuts", 2}, {"garlic", 3}};
    std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(12.99, "Pesto Pasta", "Cook", ingredients1);

    std::unordered_map<std::string, int> ingredients2 = {{"salt", 2}, {"pepper", 1}, {"garlic", 3}};
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(10.99, "Spaghetti Carbonara", "Baker", ingredients2);

    std::unordered_map<std::string, int> ingredients3 = {{"lemon", 2}, {"pepper", 1}, {"wings", 3}};
    std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(10.99, "Lemon pepper wings", "Grill chef", ingredients3);
    
    //vector of meals
    std::vector <std::shared_ptr<Meal>> meals = {meal1, meal2, meal3};

    //shared_ptr<Management> management
    Management* management = new Management();
    
    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management, meals);
    
    //check ingredients
    kitchen->createHeadChef();
    EXPECT_NE(kitchen->getHeadChef(), nullptr);
}

TEST(KitchenTest, AddOrderSuccess){
    // Create some meals with ingredients
    std::unordered_map<std::string, int> ingredients1;
    ingredients1["spaghetti"] = 200;
    ingredients1["bacon"] = 100;
    ingredients1["eggs"] = 2;
    ingredients1["parmesan cheese"] = 50;
    std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(100.0, "Spaghetti Carbonara", "Cook", ingredients1);

    std::unordered_map<std::string, int> ingredients2;
    ingredients2["pizza dough"] = 300;
    ingredients2["tomato sauce"] = 100;
    ingredients2["mozzarella cheese"] = 150;
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(140.60,"Margherita Pizza","Grill Chef",ingredients2);

    std::unordered_map<std::string, int> ingredients3;
    ingredients3["lettuce"] = 100;
    ingredients3["chicken breast"] = 200;
    ingredients3["croutons"] = 50;
    ingredients3["parmesan cheese"] = 50;
    std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(120.0,"Caesar Salad","Baker",ingredients3);

    std::unordered_map<std::string, int> ingredients4;
    ingredients4["lemon"] = 100;
    ingredients4["water"] = 200;
    ingredients4["sugar"] = 50;
    ingredients4["ice"] = 50;
    std::shared_ptr<Meal> meal4 = std::make_shared<Meal>(120.0,"Lemonade","Deputy Head Chef",ingredients4);

    //creating the meals vector
    std::vector<std::shared_ptr<Meal>> mealsVec;
    mealsVec.push_back(meal1);
    mealsVec.push_back(meal2);
    mealsVec.push_back(meal3);
    mealsVec.push_back(meal4);

    // creating the shared pointer for the meals
    std::shared_ptr<Food> meal1Ptr = std::make_shared<Food>(meal1->getPrice(), meal1->getName(), meal1->getIngredients());
    std::shared_ptr<Food> meal2Ptr = std::make_shared<Food>(meal2->getPrice(), meal2->getName(), meal2->getIngredients());
    std::shared_ptr<Food> meal3Ptr = std::make_shared<Food>(meal3->getPrice(), meal3->getName(), meal3->getIngredients());
    std::shared_ptr<Beverage> meal4Ptr = std::make_shared<Beverage>(false,meal4->getPrice(), meal4->getName(), meal4->getIngredients());
    
    //creating the vector for the meals
    std::vector<std::shared_ptr<MenuItem>> meals;

    meals.push_back(meal1Ptr);
    meals.push_back(meal2Ptr);
    meals.push_back(meal3Ptr);
    meals.push_back(meal4Ptr);

    // create the waiter
    std::shared_ptr<Waiter> waiter = std::make_shared<Waiter>("Thato", 1);

    // Create an order with the meals
    std::shared_ptr<Order> order = std::make_shared<Order>(1,meals,waiter);

    //create invertory
    std::unordered_map<std::string, int> inven;
    inven["spaghetti"] = 200;
    inven["bacon"] = 100;
    inven["eggs"] = 2;
    inven["parmesan cheese"] = 50;
    inven["pizza dough"] = 300;
    inven["tomato sauce"] = 100;
    inven["mozzarella cheese"] = 1000;;
    inven["lettuce"] = 1000;
    inven["chicken breast"] = 1000;
    inven["croutons"] = 1000;
    inven["parmesan cheese"] = 1000;
    inven["lemon"] = 1000;
    inven["water"] = 1000;
    inven["sugar"] = 1000;
    inven["ice"] = 1000;

    std::shared_ptr<Inventory> inventory = std::make_shared<Inventory>(inven);

    //create management
    Management* management = new Management();
    management->setInventory(inventory);

    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management, mealsVec);

    kitchen->addOrder(order);

    EXPECT_EQ(kitchen->getPreparedOrders().size(),1);

}

TEST(KitchenTest, AddOrderFail){
    // Create some meals with ingredients
    std::unordered_map<std::string, int> ingredients1;
    ingredients1["spaghetti"] = 200;
    ingredients1["bacon"] = 100;
    ingredients1["eggs"] = 2;
    ingredients1["parmesan cheese"] = 50;
    std::shared_ptr<Meal> meal1 = std::make_shared<Meal>(100.0, "Spaghetti Carbonara", "Cook", ingredients1);

    std::unordered_map<std::string, int> ingredients2;
    ingredients2["pizza dough"] = 300;
    ingredients2["tomato sauce"] = 100;
    ingredients2["mozzarella cheese"] = 150;
    std::shared_ptr<Meal> meal2 = std::make_shared<Meal>(140.60,"Margherita Pizza","Grill",ingredients2);

    std::unordered_map<std::string, int> ingredients3;
    ingredients3["lettuce"] = 100;
    ingredients3["chicken breast"] = 200;
    ingredients3["croutons"] = 50;
    ingredients3["parmesan cheese"] = 50;
    std::shared_ptr<Meal> meal3 = std::make_shared<Meal>(120.0,"Caesar Salad","Baker",ingredients3);

    std::unordered_map<std::string, int> ingredients4;
    ingredients4["lemon"] = 100;
    ingredients4["water"] = 200;
    ingredients4["sugar"] = 50;
    ingredients4["ice"] = 50;
    std::shared_ptr<Meal> meal4 = std::make_shared<Meal>(120.0,"Lemonade","Deputy Head Chef",ingredients4);

    //creating the meals vector
    std::vector<std::shared_ptr<Meal>> mealsVec;
    mealsVec.push_back(meal1);
    mealsVec.push_back(meal2);
    mealsVec.push_back(meal3);
    mealsVec.push_back(meal4);

    // creating the shared pointer for the meals
    std::shared_ptr<Food> meal1Ptr = std::make_shared<Food>(meal1->getPrice(), meal1->getName(), meal1->getIngredients());
    std::shared_ptr<Food> meal2Ptr = std::make_shared<Food>(meal2->getPrice(), meal2->getName(), meal2->getIngredients());
    std::shared_ptr<Food> meal3Ptr = std::make_shared<Food>(meal3->getPrice(), meal3->getName(), meal3->getIngredients());
    std::shared_ptr<Beverage> meal4Ptr = std::make_shared<Beverage>(false,meal4->getPrice(), meal4->getName(), meal4->getIngredients());
    
    //creating the vector for the meals
    std::vector<std::shared_ptr<MenuItem>> meals;

    meals.push_back(meal1Ptr);
    meals.push_back(meal2Ptr);
    meals.push_back(meal3Ptr);
    meals.push_back(meal4Ptr);

    // create the waiter
    std::shared_ptr<Waiter> waiter = std::make_shared<Waiter>("Thato", 1);

    // Create an order with the meals
    std::shared_ptr<Order> order = std::make_shared<Order>(1,meals,waiter);

    //create invertory
    std::unordered_map<std::string, int> inven;
    inven["spaghetti"] = 0;
    inven["bacon"] = 100;
    inven["eggs"] = 2;
    inven["parmesan cheese"] = 50;
    inven["pizza dough"] = 300;
    inven["tomato sauce"] = 100;
    inven["mozzarella cheese"] = 150;
    inven["lettuce"] = 100;
    inven["chicken breast"] = 200;
    inven["croutons"] = 50;
    inven["parmesan cheese"] = 50;
    inven["lemon"] = 100;
    inven["water"] = 200;
    inven["sugar"] = 50;
    inven["ice"] = 50;

    std::shared_ptr<Inventory> inventory = std::make_shared<Inventory>(inven);

    //create management
    Management* management = new Management();
    management->setInventory(inventory);

    //kitchen
    std::shared_ptr<Kitchen> kitchen = std::make_shared<Kitchen>(management, mealsVec);

    kitchen->addOrder(order);

    EXPECT_EQ(kitchen->getCanceledOrder(waiter),order);

}