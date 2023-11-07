#include "Accounting.h"
#include "CashBill.h"
#include "CardBill.h"
#include "MultiBill.h"

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

}

double Accounting::getBalance()
{
    return balance;
}