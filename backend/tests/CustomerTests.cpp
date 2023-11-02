// #include <gtest/gtest.h>
// #include <memory>

// #include "./includes/include_all.h"

// TEST(CustomerTest, ConstructorTest) {
//     std::shared_ptr<Management> management = std::make_shared<Management>();
//     std::shared_ptr<Customer>  customer = std::make_shared<Customer>(management);
//     customer->setManagement(management);

//     EXPECT_EQ(customer->getName(), "Main Character");
//     EXPECT_EQ(customer->getMood()->getStateName(), "Happy");
//     EXPECT_FALSE(customer->IsReadyToOrder());
//     EXPECT_EQ(customer->getTotalBill(), 0);
//     EXPECT_EQ(customer->getManagement(), management);
// }

// TEST(CustomerTest, MoodChange) {
//     std::shared_ptr<Management> management = std::make_shared<Management>();
//     std::shared_ptr<Customer>  customer = std::make_shared<Customer>(management);
//     customer->setManagement(management);

//     EXPECT_EQ(customer->getName(), "Main Character");
//     EXPECT_EQ(customer->getMood()->getStateName(), "Happy");
//     EXPECT_FALSE(customer->IsReadyToOrder());
//     EXPECT_EQ(customer->getTotalBill(), 0);
//     EXPECT_EQ(customer->getManagement(), management);

//     customer->anger();
//     EXPECT_EQ(customer->getMood()->getStateName(), "Neutral");

//     customer->anger();
//     EXPECT_EQ(customer->getMood()->getStateName(), "Unhappy");
    
// }

