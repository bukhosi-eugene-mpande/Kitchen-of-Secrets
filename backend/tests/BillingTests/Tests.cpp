#include "gtest/gtest.h"

#include "../includes/include_all.h"
#include "../includes/include_all.cpp"

TEST(BillingTests, BillingContructorTest) {
    std::shared_ptr<Accounting> accounting = std::make_shared<Accounting>();
    EXPECT_EQ(accounting->getBalance(), 0.0);
}

TEST(BillingTests, PaymentTypeTests) {
    std::shared_ptr<Accounting> accounting = std::make_shared<Accounting>();

    std::string paymentData = accounting->pay(10.0, "cash");

    EXPECT_EQ(paymentData,"Cash Payment successful");

    paymentData = accounting->pay(10.0, "card");

    EXPECT_EQ(paymentData,"Card Payment successful");

    paymentData = accounting->pay(10.0, "multi");

    EXPECT_EQ(paymentData,"Multi Payment successful");

}

TEST(BillingTests, TabTests) {
    std::shared_ptr<Tab> tab = std::make_shared<Tab>();

    tab->addOrderCost(10.0);
    tab->addOrderCost(10.0);
    tab->addOrderCost(10.0);

    EXPECT_EQ(tab->getBillTotal(),30.0);

    std::string tabData = tab->closeTab();

    EXPECT_EQ(tabData,"Tab closed successfully");

    tabData = tab->addOrderCost(11.0);

    EXPECT_EQ(tabData,"Tab is closed");

}
