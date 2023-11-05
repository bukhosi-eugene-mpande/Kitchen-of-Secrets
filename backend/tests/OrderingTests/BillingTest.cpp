#include "../includes/customercare_all.cpp"
#include "../includes/reservation_all.cpp"
#include "../includes/inventory_all.cpp"
#include "../includes/ordering_all.cpp"
#include "../includes/cooking_all.cpp"
#include "../includes/management_all.cpp"
#include "gtest/gtest.h"
#include <memory>

// Include the necessary headers for your classes

// Test fixture

TEST(WaiterServeBillTest, ServeBillWhenCustomerIsReadyToPay) {
       // std::shared_ptr<Order> order;
        std::shared_ptr<CustomerTemplate> customer;
        std::shared_ptr<Management> management;
        std::shared_ptr<Table> table;
        std::shared_ptr<Section> section;
        
        management = std::make_shared<Management>();
        Management* mngPtr=management.get();
        // Section
        section = std::make_shared<Section>("Test Section", 5);
        Section* sectionPtr=section.get();

        // Waiter
        std::shared_ptr<Waiter> waiterPtr = std::make_shared<Waiter>(sectionPtr, mngPtr);


        // Table
        table = std::make_shared<Table>("private", 2);
        // Customer
        customer = std::make_shared<CustomerTemplate>("John Doe", management);

        customer->setPaymentType("credit");
        customer->setIsDoneEating();

        std::unordered_map<std::string, int> ingredients1 = {{"flour", 2}, {"sugar", 1}};
        std::shared_ptr<MenuItem> meal1 = std::make_shared<Food>(8.50, "John", ingredients1);

        std::unordered_map<std::string, int> ingredients2 = {{"water", 1}, {"sugar", 2}};
        std::shared_ptr<MenuItem> meal2 = std::make_shared<Beverage>(false, 2.99,  "Alice", ingredients2);

        // Create an OrderBuilder
        std::shared_ptr<OrderBuilder> orderBuilder = std::make_shared<OrderBuilder>();

        // Add meals to the order
        orderBuilder->addMeal(meal1);
        orderBuilder->addMeal(meal2);

        // Get the final order
        std::shared_ptr<Order> order = orderBuilder->getOrder();


        // Order
        //order = std::make_shared<Order>(table, meals, &waiter);
        customer->setFinishedOrder(order);

        // Add the customer to the table in the section
        table->addCustomer(customer);
        section->addTable(table);

    // void SetUp() override {
        
    // }
    

    // void TearDown() override {
    //     // Perform cleanup here if needed
    // }


// Test case for serveBill

    // Act
    waiterPtr->serveBill();

       EXPECT_TRUE(customer->IsReadyToPay());

    // 2. Check if the customer's total bill matches the calculated bill
    double finalBill = order->calculatePrice();
    EXPECT_DOUBLE_EQ(finalBill, customer->getTotalBill());

    // 3. Check if the customer has not left (immediately after bill serving)
    EXPECT_FALSE(customer->getIsDoneEating());

    // 4. Check if the customer is marked as done eating (if they are ready to pay)
    if (customer->IsReadyToPay()) {
        EXPECT_TRUE(customer->getIsDoneEating());
        
        // 5. Check if the bill is sent to management
        // Assuming you have a function to check if the bill was sent to management
        // Replace this with your actual implementation
        EXPECT_TRUE(management->hasReceivedBill());
    }
}
