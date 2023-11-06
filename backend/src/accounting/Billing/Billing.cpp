#include "Billing.h"

Billing::Billing(BillStrategy *billStrategy)
{
    this->billStrategy = billStrategy;
}

std::string Billing::pay(double amount)
{
    return billStrategy->pay(amount);
}