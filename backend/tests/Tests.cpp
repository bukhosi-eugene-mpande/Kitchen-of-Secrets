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

TEST(CustomerTest, MoodChange) {
    std::shared_ptr<Management> management = std::make_shared<Management>();
    std::shared_ptr<Customer>  customer = std::make_shared<Customer>(management);
    customer->setManagement(management);

    EXPECT_EQ(customer->getName(), "Main Character");
    EXPECT_EQ(customer->getMood()->getStateName(), "Happy");
    EXPECT_FALSE(customer->IsReadyToOrder());
    EXPECT_EQ(customer->getTotalBill(), 0);
    EXPECT_EQ(customer->getManagement(), management);

    customer->anger();
    EXPECT_EQ(customer->getMood()->getStateName(), "Neutral");

    customer->anger();
    EXPECT_EQ(customer->getMood()->getStateName(), "Unhappy");

    customer->console();
    EXPECT_EQ(customer->getMood()->getStateName(), "Neutral");

    customer->anger();
    EXPECT_EQ(customer->getMood()->getStateName(), "Unhappy");
    
}

TEST(CustomerTest, ReservationTest) {
    std::shared_ptr<Management> management = std::make_shared<Management>();
    Customer*  customer1 = new Customer(management);
    Customer*  customer2 = new Customer(management);

    customer1->setManagement(management);
    customer2->setDesiredSection("General Section");
    customer1->requestReservation();

    customer2->setManagement(management);
    customer2->setDesiredSection("Private Section");
    customer2->requestReservation();

    EXPECT_NE(customer1->getReservation(), nullptr);

    EXPECT_NE(customer2->getReservation(), nullptr);
    
}

