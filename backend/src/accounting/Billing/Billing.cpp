#include "Billing.h"

Billing::Billing(BillStrategy *billStrategy)
{
    this->billStrategy = billStrategy;
}

void Billing::pay(double amount)
{
    billStrategy->pay(amount);
}