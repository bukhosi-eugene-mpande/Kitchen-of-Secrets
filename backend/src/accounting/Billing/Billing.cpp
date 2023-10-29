#include "Billing.h"

Billing::Billing(BillStrategy *billStrategy)
{
    this->billStrategy = billStrategy;
}

json Billing::pay(double amount)
{
    return billStrategy->pay(amount);
}