#include <gtest/gtest.h>
#include <memory>

#include "./includes/customercare_all.cpp"
#include "./includes/reservation_all.cpp"
#include "./includes/inventory_all.cpp"
#include "./includes/ordering_all.cpp"
#include "./includes/cooking_all.cpp"
#include "./includes/management_all.cpp"

TEST(CustomerTest, ConstructorTest) {
    std::shared_ptr<Management> management = std::make_shared<Management>();
    std::shared_ptr<Customer>  customer = std::make_shared<Customer>(management);
    customer->setManagement(management);

    EXPECT_EQ(customer->getName(), "Main Character");
    EXPECT_EQ(customer->getMood()->getStateName(), "Happy");
    EXPECT_FALSE(customer->IsReadyToOrder());
    EXPECT_EQ(customer->getTotalBill(), 0);
    EXPECT_EQ(customer->getManagement(), management);
}