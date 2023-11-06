#include "Accounting.h"
#include "Billing/CashBill.h"
#include "Billing/CardBill.h"
#include "Billing/MultiBill.h"

Accounting::Accounting()
{
    balance = 0.0;
}

std::string Accounting::closeTab()
{
    Tab *tab = new Tab();
    std::string tabData = tab->closeTab();
    balance += 10;
    return tabData;
}

std::string Accounting::pay(double amount, std::string paymentType){
    if (paymentType == "cash")
    {
        billing = new Billing(new CashBill(amount));
    }
    else if (paymentType == "card")
    {
        billing = new Billing(new CardBill(amount));
    }
    else if (paymentType == "multi")
    {
        billing = new Billing(new MultiBill(amount));
    }
    else
    {
        return "Invalid payment type";
    }

    std::string paymentData = billing->pay(amount);
    balance -= amount;
    return paymentData;
}

Accounting::~Accounting()
{
    delete tab;
    delete billing;
    delete inventory;
}